/* Per-project checks. Add to this table as projects get written.
 *
 * A check runs the project's binary with optional stdin and arguments, then
 * asserts something about what came back. The student writes the program; this
 * decides whether it works.
 */
#ifndef CHECKS_H
#define CHECKS_H

typedef enum {
    LINE_IS,          /* stdout line `line` equals `want`; negative counts from the end */
    LINE_COUNT,       /* number of non-empty stdout lines equals `line` */
    NO_TRAILING_BLANK,/* stdout does not end with a blank line */
    NO_TRAILING_WS,   /* no stdout line has trailing whitespace */
    NO_PANIC,         /* stderr contains no Rust panic */
    EXIT_ZERO,
    EXIT_NONZERO
} Kind;

typedef struct {
    const char *name;      /* shown in the report */
    const char *input;     /* piped to stdin, or NULL */
    const char *args[6];   /* NULL-terminated, or all NULL */
    Kind kind;
    int line;              /* LINE_IS index, or LINE_COUNT expected count */
    const char *want;
} Check;

typedef struct {
    const char *slug;
    const Check *checks;
    int n;
} Project;

static const Check c_hello[] = {
 {"greets the name given",        "Chace\n",     {0}, LINE_IS, 1, "Hello, Chace"},
 {"no stray blank line",          "Chace\n",     {0}, NO_TRAILING_BLANK, 0, 0},
 {"trims surrounding whitespace", "  Chace  \n", {0}, LINE_IS, 1, "Hello, Chace"},
 {"survives empty input",         "\n",          {0}, NO_PANIC, 0, 0},
 {"survives EOF with no newline", "",            {0}, NO_PANIC, 0, 0},
 {"exits cleanly",                "Chace\n",     {0}, EXIT_ZERO, 0, 0},
};

static const Check c_credit[] = {
 {"valid VISA",        "4003600000000014\n", {0}, LINE_IS, -1, "VISA"},
 {"valid AMEX",        "378282246310005\n",  {0}, LINE_IS, -1, "AMEX"},
 {"valid MASTERCARD",  "5555555555554444\n", {0}, LINE_IS, -1, "MASTERCARD"},
 {"fails Luhn",        "1234567890123456\n", {0}, LINE_IS, -1, "INVALID"},
 {"too short",         "1234\n",             {0}, LINE_IS, -1, "INVALID"},
 {"junk input",        "hello\n",            {0}, NO_PANIC, 0, 0},
};

static const Check c_mario[] = {
 {"height 1 is two blocks",  "1\n",     {0}, LINE_IS, -1, "  #  #"},
 {"no trailing whitespace",  "4\n",     {0}, NO_TRAILING_WS, 0, 0},
 {"reprompts on 0",          "0\n1\n",  {0}, NO_PANIC, 0, 0},
 {"reprompts on junk",       "abc\n1\n",{0}, NO_PANIC, 0, 0},
};

static const Check c_fizz[] = {
 {"1 prints 1",         0, {0}, LINE_IS, 0,  "1"},
 {"3 prints Fizz",      0, {0}, LINE_IS, 2,  "Fizz"},
 {"5 prints Buzz",      0, {0}, LINE_IS, 4,  "Buzz"},
 {"15 prints FizzBuzz", 0, {0}, LINE_IS, 14, "FizzBuzz"},
 {"100 lines of output",0, {0}, LINE_COUNT, 100, 0},
 {"exits cleanly",      0, {0}, EXIT_ZERO, 0, 0},
};

static const Check c_scrabble[] = {
 {"higher score wins",  "Question\nPlace\n", {0}, LINE_IS, -1, "Player 1 wins!"},
 {"ties reported",      "hello\nhello\n",    {0}, LINE_IS, -1, "Tie!"},
 {"ignores non-letters","hello!!!\nhello\n", {0}, LINE_IS, -1, "Tie!"},
 {"no panic on empty",  "\n\n",              {0}, NO_PANIC, 0, 0},
};

static const Check c_caesar[] = {
 {"shifts by key",      "HELLO\n", {"1", 0}, LINE_IS, -1, "IFMMP"},
 {"wraps at Z",         "Zz\n",    {"1", 0}, LINE_IS, -1, "Aa"},
 {"leaves punctuation", "a, b\n",  {"1", 0}, LINE_IS, -1, "b, c"},
 {"key 0 is identity",  "abc\n",   {"0", 0}, LINE_IS, -1, "abc"},
 {"missing key fails",  0,         {0},      EXIT_NONZERO, 0, 0},
 {"junk key fails",     0,         {"x", 0}, EXIT_NONZERO, 0, 0},
};

#define P(slug, arr) { slug, arr, (int)(sizeof(arr)/sizeof((arr)[0])) }
static const Project PROJECTS[] = {
    P("01-hello-its-me", c_hello),
    P("02-credit",       c_credit),
    P("03-mario",        c_mario),
    P("05-fizz",         c_fizz),
    P("06-scrabble",     c_scrabble),
    P("10-caesar",       c_caesar),
};
#undef P
static const int N_PROJECTS = (int)(sizeof(PROJECTS)/sizeof(PROJECTS[0]));

#endif
