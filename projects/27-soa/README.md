# 27. Structure of arrays

Tier 3 — Binary and memory

## Why this one

The memory layout ayatsuri2d's runtime is built on. Measure why it matters.

## What it must do

- Model 10k particles twice: array-of-structs and struct-of-arrays.
- Update only one field across all of them, both ways.
- Time both and report the difference.
- Explain the result in the README.

## Pass criteria

Both implementations correct; timings recorded; written explanation of the gap.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- cache locality
- Vec<T> layout
- std::time::Instant
- measuring rather than guessing

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

- Predict the result before you measure. Then find out if you were right.
- docs/goals.md chose SoA for this reason; this is you verifying the claim.

## Neighbours

Previous: `../26-roundtrip/`
Next: `../28-errors/`
