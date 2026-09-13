# 30. Dynamic dispatch versus generics

Tier 4: Abstraction and proof

## Why this one

The C ABI forces this decision. Understand the trade before it is load bearing.

## What it must do

- Define a trait with several implementors.
- Write the same driver twice: once generic, once with dyn.
- Measure the call overhead of each.
- Write up when each is the right choice.

## Pass criteria

Both implementations correct; measurements recorded; written conclusion.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- dyn Trait
- trait objects
- monomorphisation
- object safety

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

- Not every trait can be a trait object. Find out what breaks object safety.
- The C ABI cannot expose generics. This decides your crate boundaries.

## Neighbours

Previous: `../29-iterator/`
Next: `../31-threads/`
