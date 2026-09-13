# Marking criteria

Every project in `projects/` is marked against this. It does not change between
projects, so progress across them is comparable.

Ask for a mark whenever you want one. Partial work is fine to submit — the
point is to show where the gaps are, not to withhold a grade until perfect.

---

## The six categories

### 1. Correctness — does it do the job

    MET       meets the project's stated pass criteria in full
    PARTIAL   works for the common case, fails an edge case or a stated rule
    NOT MET   does not run, or produces wrong output on the main path

Checked by running it, not by reading it.

### 2. Safety — can it be made to crash

    MET       no unwrap, expect or panic outside tests. No raw indexing where
              the index is not provably in range. Bad input produces an error.
    PARTIAL   handles the obvious failures, panics on an unusual one
    NOT MET   unwrap or expect on the main path, or panics on malformed input

Ayatsuri2D's `docs/goals.md` forbids `unwrap`, `expect`, `panic!` and raw
indexing on the runtime path. This category is that rule, practised early.

### 3. Memory — is the work bounded

    MET       reads in chunks, allocates outside hot loops, no whole-file slurp
              unless the size is genuinely bounded and that is stated
    PARTIAL   works but allocates more than it needs to
    NOT MET   loads unbounded input into memory, or allocates per iteration

From `goals.md`: allocation happens at load, the frame loop allocates nothing.

### 4. Idiom — does it read like Rust

    MET       cargo clippy clean, cargo fmt clean
    PARTIAL   a handful of clippy warnings
    NOT MET   many warnings, or fights the language

Run `cargo clippy` before asking. It is free marks and it teaches idiom faster
than being told.

### 5. Structure — is it composed

    MET       split into functions with names that say what they do; main is
              short; no function doing three unrelated things
    PARTIAL   mostly one long function but the logic is clear
    NOT MET   everything in main, deep nesting, repeated blocks

### 6. Tests — is correctness checked by something other than you

    MET       tests covering the happy path and at least the rejection cases
              the project names
    PARTIAL   some tests, gaps in the failure paths
    NOT MET   none

---

## Mark format

    PROJECT   NN-slug
    ─────────────────────────────────────────────
    correctness   MET / PARTIAL / NOT MET   note
    safety        ...
    memory        ...
    idiom         ...
    structure     ...
    tests         ...
    ─────────────────────────────────────────────
    OVERALL       n/6 met
    NEXT          the single highest-value thing to fix

Only one `NEXT`. A list of six things to fix is a list nobody acts on.

---

## Authorship

A separate line, because it is the thing that actually matters for learning.

    WROTE IT      you typed it, errors and all
    GUIDED        you typed it after being told what was wrong
    CO-WRITTEN    the approach was yours, some of the code was not
    HANDED OVER   it was written for you

A project can be 6/6 and still be HANDED OVER. That is a pass for the code and
not for you, and the mark will say so plainly. Ask for hints rather than fixes
if you want the first two.

---

## Asking for help without losing the mark

These do not affect authorship:

- what an error message means
- which concept applies here
- where in the docs to look
- why an approach will not work
- reviewing code you wrote and naming what is wrong

This does:

- being given the corrected code

Both are legitimate requests. Just be aware which one you are making.
