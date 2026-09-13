# 02. Validate a card number

Tier 0 — On-ramp

## Why this one

Your CS50 credit pset in Rust. Pure arithmetic and control flow, no I/O to trip over.

## What it must do

- Read a card number from the command line or stdin.
- Run Luhn's algorithm over its digits.
- Print AMEX, MASTERCARD, VISA or INVALID based on length and prefix.
- Non-numeric input is rejected, not panicked on.

## Pass criteria

Matches your C version's output on the standard test numbers; junk input errors cleanly.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- integer arithmetic
- while loops
- functions returning values
- early return

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

- Your C version walked digits with % 10 and / 10. Rust can do that, or you can work over the digits as a sequence. Try both and compare which reads better.
- Deciding the card type is a separate job from validating it. Two functions.

## Neighbours

Previous: `../01-hello-its-me/`
Next: `../03-mario/`
