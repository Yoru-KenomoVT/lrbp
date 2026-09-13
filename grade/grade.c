/* grade, run a project's binary against its checks and report.
 *
 *   ./grade                 list projects that have checks
 *   ./grade 01-hello-its-me run that project's checks
 *   ./grade all             run everything that has checks
 *
 * Builds the crate with cargo first, then forks the binary once per check,
 * feeding it stdin over a pipe and capturing stdout, stderr and exit code.
 */
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
#include "checks.h"

#define CAP (1 << 20)

static const char *GREEN = "\033[32m", *RED = "\033[31m",
                  *DIM = "\033[2m", *BOLD = "\033[1m", *OFF = "\033[0m";

typedef struct { char *out; char *err; int rc; int timed_out; } Run;

/* Drain a fd into a fresh buffer. */
static char *slurp(int fd) {
    char *buf = malloc(CAP);
    size_t n = 0;
    ssize_t r;
    if (!buf) return NULL;
    while (n + 1 < CAP && (r = read(fd, buf + n, CAP - n - 1)) > 0) n += (size_t)r;
    buf[n] = '\0';
    return buf;
}

static Run run_once(const char *bin, const Check *c) {
    Run rv = {0};
    int pin[2], pout[2], perr[2];
    if (pipe(pin) || pipe(pout) || pipe(perr)) { perror("pipe"); exit(1); }

    pid_t pid = fork();
    if (pid < 0) { perror("fork"); exit(1); }

    if (pid == 0) {
        dup2(pin[0], 0); dup2(pout[1], 1); dup2(perr[1], 2);
        close(pin[0]); close(pin[1]);
        close(pout[0]); close(pout[1]);
        close(perr[0]); close(perr[1]);

        char *argv[8];
        int a = 0;
        argv[a++] = (char *)bin;
        for (int i = 0; i < 6 && c->args[i]; i++) argv[a++] = (char *)c->args[i];
        argv[a] = NULL;
        alarm(10);                      /* a hung program must not hang the grader */
        execv(bin, argv);
        _exit(127);
    }

    close(pin[0]); close(pout[1]); close(perr[1]);
    if (c->input && *c->input) {
        size_t len = strlen(c->input), off = 0;
        while (off < len) {
            ssize_t w = write(pin[1], c->input + off, len - off);
            if (w <= 0) break;          /* child exited early; that is its choice */
            off += (size_t)w;
        }
    }
    close(pin[1]);                      /* EOF, so a reader loop can finish */

    rv.out = slurp(pout[0]);
    rv.err = slurp(perr[0]);
    close(pout[0]); close(perr[0]);

    int st = 0;
    waitpid(pid, &st, 0);
    if (WIFEXITED(st)) rv.rc = WEXITSTATUS(st);
    else if (WIFSIGNALED(st)) { rv.rc = 128 + WTERMSIG(st); rv.timed_out = (WTERMSIG(st) == SIGALRM); }
    return rv;
}

/* Split stdout into lines, dropping trailing empties. Caller frees `lines`. */
static int split_lines(char *out, char ***lines) {
    int cap = 64, n = 0;
    char **v = malloc((size_t)cap * sizeof *v);
    char *p = out;
    while (*p) {
        char *nl = strchr(p, '\n');
        if (n == cap) { cap *= 2; v = realloc(v, (size_t)cap * sizeof *v); }
        if (!nl) { v[n++] = p; break; }
        *nl = '\0';
        v[n++] = p;
        p = nl + 1;
    }
    while (n > 0 && v[n-1][0] == '\0') n--;
    *lines = v;
    return n;
}

static int judge(const Check *c, Run *r, char *detail, size_t dn) {
    detail[0] = '\0';
    if (r->timed_out) { snprintf(detail, dn, "timed out after 10s"); return 0; }
    if (r->rc == 127)  { snprintf(detail, dn, "binary would not execute"); return 0; }

    char **L = NULL;
    int n = split_lines(r->out, &L);
    int ok = 0;

    switch (c->kind) {
    case LINE_IS: {
        int idx = c->line < 0 ? n + c->line : c->line;
        if (idx < 0 || idx >= n) { snprintf(detail, dn, "wanted line %d, got %d line(s)", c->line, n); break; }
        ok = strcmp(L[idx], c->want) == 0;
        if (!ok) snprintf(detail, dn, "got \"%s\", wanted \"%s\"", L[idx], c->want);
        break; }
    case LINE_COUNT:
        ok = (n == c->line);
        if (!ok) snprintf(detail, dn, "got %d lines, wanted %d", n, c->line);
        break;
    case NO_TRAILING_BLANK: {
        size_t len = strlen(r->out);
        ok = !(len >= 2 && r->out[len-1] == '\n' && r->out[len-2] == '\n');
        if (!ok) snprintf(detail, dn, "output ends with a blank line");
        break; }
    case NO_TRAILING_WS:
        ok = 1;
        for (int i = 0; i < n; i++) {
            size_t l = strlen(L[i]);
            if (l && (L[i][l-1] == ' ' || L[i][l-1] == '\t')) {
                ok = 0; snprintf(detail, dn, "line %d has trailing whitespace", i + 1); break;
            }
        }
        break;
    case NO_PANIC:
        ok = strstr(r->err, "panicked at") == NULL;
        if (!ok) {
            char *p = strstr(r->err, "panicked at");
            char *nl = strchr(p, '\n'); if (nl) *nl = '\0';
            snprintf(detail, dn, "%s", p);
        }
        break;
    case EXIT_ZERO:
        ok = (r->rc == 0);
        if (!ok) snprintf(detail, dn, "exit code %d", r->rc);
        break;
    case EXIT_NONZERO:
        ok = (r->rc != 0);
        if (!ok) snprintf(detail, dn, "exit code 0, wanted non-zero");
        break;
    }
    free(L);
    return ok;
}

static int grade_project(const Project *p, const char *root) {
    char dir[5120], bin[6144], cmd[12288];
    snprintf(dir, sizeof dir, "%s/projects/%s", root, p->slug);

    const char *name = strchr(p->slug, '-');
    name = name ? name + 1 : p->slug;
    char crate[128];
    snprintf(crate, sizeof crate, "%s", name);
    for (char *q = crate; *q; q++) if (*q == '-') *q = '_';

    printf("\n%s%s%s\n", BOLD, p->slug, OFF);

    /* Always rebuild. Touching the sources defeats cargo's freshness cache, so a
     * stale binary from a previous run can never be graded by accident. Build
     * output is captured and only shown when it fails. */
    char log[256];
    snprintf(log, sizeof log, "/tmp/grade-build-%d.log", (int)getpid());
    snprintf(bin, sizeof bin, "%s/target/debug/%s", dir, crate);
    unlink(bin);                        /* no binary at all beats a stale one */

    snprintf(cmd, sizeof cmd,
             "cd '%s' && find src -name '*.rs' -exec touch {} + 2>/dev/null; "
             "cargo build --quiet >'%s' 2>&1", dir, log);
    int build_rc = system(cmd);

    if (build_rc != 0 || access(bin, X_OK) != 0) {
        printf("  %sbuild failed%s\n\n", RED, OFF);
        FILE *f = fopen(log, "r");
        if (f) {
            char line[1024];
            int shown = 0;
            while (fgets(line, sizeof line, f) && shown < 40) { printf("    %s", line); shown++; }
            fclose(f);
        }
        unlink(log);
        printf("\n  %s0/%d%s  (nothing ran)\n", RED, p->n, OFF);
        return p->n;
    }
    unlink(log);

    int failed = 0;
    char detail[512];
    for (int i = 0; i < p->n; i++) {
        const Check *c = &p->checks[i];
        Run r = run_once(bin, c);
        int ok = judge(c, &r, detail, sizeof detail);
        printf("  %s%s%s  %-34s", ok ? GREEN : RED, ok ? "PASS" : "FAIL", OFF, c->name);
        if (!ok && detail[0]) printf("  %s%s%s", DIM, detail, OFF);
        putchar('\n');
        if (!ok) failed++;
        free(r.out); free(r.err);
    }
    printf("  %s%d/%d%s\n", failed ? RED : GREEN, p->n - failed, p->n, OFF);
    return failed;
}

/* Walk up from `start` until we find the rust_learn root, identified by having
 * both criteria.md and a projects/ directory. Returns 1 on success. */
static int find_root(char *out, size_t n) {
    char cur[4096];
    if (!getcwd(cur, sizeof cur)) return 0;
    for (;;) {
        char probe[4200];
        snprintf(probe, sizeof probe, "%s/criteria.md", cur);
        if (access(probe, R_OK) == 0) {
            snprintf(probe, sizeof probe, "%s/projects", cur);
            if (access(probe, X_OK) == 0) { snprintf(out, n, "%s", cur); return 1; }
        }
        char *slash = strrchr(cur, '/');
        if (!slash || slash == cur) return 0;
        *slash = '\0';
    }
}

/* If the current directory IS a project, return its slug. */
static const char *slug_from_cwd(void) {
    static char cur[4096];
    if (!getcwd(cur, sizeof cur)) return NULL;
    const char *base = strrchr(cur, '/');
    base = base ? base + 1 : cur;
    for (int i = 0; i < N_PROJECTS; i++)
        if (strcmp(base, PROJECTS[i].slug) == 0) return PROJECTS[i].slug;
    return NULL;
}

int main(int argc, char **argv) {
    char root[4096];
    const char *env = getenv("RUST_LEARN");
    if (env) snprintf(root, sizeof root, "%s", env);
    else if (!find_root(root, sizeof root)) {
        fprintf(stderr, "not inside rust_learn (no criteria.md + projects/ above here).\n"
                        "cd into a project, or set RUST_LEARN.\n");
        return 2;
    }

    /* No argument: grade whatever project we are standing in. */
    const char *target = (argc >= 2) ? argv[1] : slug_from_cwd();
    if (!target) {
        printf("usage: grade [project-slug | all]\n");
        printf("  with no argument, grades the project you are standing in\n");
        printf("\nroot: %s\n\nprojects with checks:\n", root);
        for (int i = 0; i < N_PROJECTS; i++)
            printf("  %-18s %d checks\n", PROJECTS[i].slug, PROJECTS[i].n);
        return 0;
    }

    int failed = 0, ran = 0;
    for (int i = 0; i < N_PROJECTS; i++) {
        if (strcmp(target, "all") == 0 || strcmp(target, PROJECTS[i].slug) == 0) {
            failed += grade_project(&PROJECTS[i], root);
            ran++;
        }
    }
    if (!ran) { fprintf(stderr, "no checks defined for '%s' yet\n", target); return 2; }
    printf("\n%s%s%s\n", failed ? RED : GREEN,
           failed ? "some checks failed" : "all checks passed", OFF);
    return failed ? 1 : 0;
}
