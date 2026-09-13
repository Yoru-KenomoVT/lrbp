# 03. Build a pyramid

Tier 0 — On-ramp

## Why this one

CS50 pset 1. Nested loops and getting the arithmetic of alignment right.

## What it must do

- Ask for a height between 1 and 8, reprompting until valid.
- Print two adjacent right-aligned pyramids of hashes separated by two spaces.
- No trailing whitespace on any line.
- Reject non-numeric input without panicking.

## Pass criteria

Output identical to your C version for heights 1 through 8, no trailing spaces.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- nested loops
- input validation
- string repetition
- off-by-one arithmetic

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

- The spaces before the hashes are the actual puzzle. Work out the formula on paper first.
- str::repeat exists. Using it is not cheating, it is the idiomatic answer.

## Neighbours

Previous: `../02-credit/`
Next: `../04-guessing-game/`
