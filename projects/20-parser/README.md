# 20. Tokens to a syntax tree

Tier 2 — Text and parsing

## Why this one

The second half of a parser. Recursion, precedence, and enums that hold themselves.

## What it must do

- Take the token stream from the lexer project.
- Build an AST for arithmetic with correct precedence and parentheses.
- Report a located error for malformed input rather than panicking.
- Pretty-print the tree back out so you can see what you parsed.

## Pass criteria

Correct trees for a test set including nested parens; errors carry a position.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- recursive descent
- recursive enums and Box
- operator precedence
- AST design

See `help.md` in this folder for links and common errors.

## Build order

Do not try to write the whole thing at once. Each step should compile and run
before you move to the next.

1. Get it compiling with a `main` that does nothing useful.
2. Handle the input: arguments, opening the file, failing cleanly.
3. Make the core loop run and print something you can eyeball.
4. Add the real logic, one requirement at a time.
5. Remove every unwrap and expect.
6. `cargo fmt`, then `cargo clippy`, then tests.

## Hints, shape only

- An enum that contains itself needs indirection. The compiler will tell you why.
- Precedence falls out of which function calls which. Draw it before you code it.

## Neighbours

Previous: `../19-lexer/`
Next: `../21-interpreter/`
