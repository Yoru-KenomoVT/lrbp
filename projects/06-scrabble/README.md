# 06. Score a word

Tier 0 — On-ramp

## Why this one

CS50 pset 2. Character arithmetic and lookup tables.

## What it must do

- Take two words and score each using Scrabble letter values.
- Ignore case and any non-alphabetic characters.
- Print which player wins, or a tie.
- Handle empty input gracefully.

## Pass criteria

Correct scores for the standard test words; non-letters ignored; ties reported.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- char methods
- ASCII arithmetic
- array indexing by character
- iterating a string

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

- In C you subtracted 'A' to get an index. Rust can do that, or you can match. Try both.
- Rust strings are UTF-8, so indexing by byte is not the same as indexing by character. Know which you want.

## Neighbours

Previous: `../05-fizz/`
Next: `../07-units/`
