# 04. Guess the number

Tier 0 — On-ramp

## Why this one

The classic first Rust program. Input, loops, matching and error handling in one.

## What it must do

- Pick a secret number between 1 and 100.
- Read a guess from stdin in a loop.
- Say too high, too low, or correct, and exit on correct.
- Non-numeric input reprompts instead of crashing.
- Count the guesses and report the total at the end.

## Pass criteria

Plays a full round, rejects junk input without crashing, reports a guess count.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- stdin input
- loop with break
- match on Ordering
- parse returning Result
- the rand crate

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

- parse gives you a Result. Matching it is how you reprompt instead of panicking.
- cmp returns an Ordering, which is an enum with exactly three variants.

## Neighbours

Previous: `../03-mario/`
Next: `../05-fizz/`
