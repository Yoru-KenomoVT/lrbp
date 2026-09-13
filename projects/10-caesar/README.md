# 10. Caesar cipher

Tier 1 — Files and bytes

## Why this one

CS50 pset 2. Character arithmetic with wraparound, and your first key validation.

## What it must do

- Take a non-negative integer key as a command-line argument.
- Encipher stdin, preserving case and leaving non-letters untouched.
- Reject a missing or non-numeric key with a usage message and non-zero exit.
- Add a decipher mode.

## Pass criteria

Round-trips through encipher then decipher; bad key exits non-zero.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- modular arithmetic
- preserving case
- argument validation
- wrapping

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

- Wraparound is modulo 26, but only after shifting to a zero base. Off-by-one lives here.
- A key of 0 and a key of 26 should behave identically. Test that.

## Neighbours

Previous: `../09-readability/`
Next: `../11-recover/`
