# 07. Convert units from the command line

Tier 0 — On-ramp

## Why this one

Arguments, floats and rejecting nonsense. The smallest real CLI tool.

## What it must do

- Take a value and a unit from the command line.
- Support at least celsius/fahrenheit and kilometres/miles, both directions.
- Print the result to two decimal places.
- Unknown units and unparseable numbers produce a usage message, not a panic.

## Pass criteria

Correct conversions both directions; bad input exits non-zero with a message.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- std::env::args
- float formatting
- match on &str
- exit codes
- eprintln!

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

- Usage messages belong on stderr, results on stdout. They are different streams.
- Decide what your program does with three arguments when it wanted two.

## Neighbours

Previous: `../06-scrabble/`
Next: `../08-todo/`
