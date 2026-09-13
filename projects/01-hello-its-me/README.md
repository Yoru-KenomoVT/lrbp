# 01. Hello, it's me

Tier 0 — On-ramp

## Why this one

Prove the toolchain works and meet the syntax. Deliberately almost free.

## What it must do

- Print a greeting using a variable, not a literal.
- Store a name, an age and a height in appropriately typed variables.
- Print them in one formatted line.
- Add a const for something that should never change and use it.

## Pass criteria

Runs, prints one formatted line, uses at least one const and one float.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- let and let mut
- integer and float types
- println! and format specifiers
- const

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

- Pick the narrowest type that fits the meaning, not just the value.
- Try removing a type annotation and see whether the compiler still copes.

## Neighbours

This is the first project.
Next: `../02-credit/`
