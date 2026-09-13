# 05. FizzBuzz, then better

Tier 0 — On-ramp

## Why this one

Control flow and functions. Then the same thing as an iterator chain.

## What it must do

- Print 1 to 100 with the usual Fizz, Buzz and FizzBuzz substitutions.
- Move the decision into a function returning a String.
- Write a second version built from an iterator chain instead of a for loop.
- Add tests for the four interesting cases.

## Pass criteria

Both versions produce identical output; four tests pass.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- functions and return values
- if/else chains
- match on tuples
- iterator chains
- unit tests

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

- A function returning String is easier to test than one that prints.
- Matching on (n % 3, n % 5) is a different shape to if/else. Try both.

## Neighbours

Previous: `../04-guessing-game/`
Next: `../06-scrabble/`
