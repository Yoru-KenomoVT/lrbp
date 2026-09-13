# 29. Implement Iterator yourself

Tier 4: Abstraction and proof

## Why this one

Your chunk reader and token stream both want to be iterators.

## What it must do

- Write a type that yields fixed-size chunks of a byte slice.
- Implement Iterator for it.
- Make it work in a for loop and with map, filter and take.
- Add a variant yielding (offset, chunk) pairs.

## Pass criteria

Works in a for loop and chains with at least three std adaptors.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- impl Trait for Type
- associated types
- lifetimes on iterators
- zero-cost abstraction

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

- The Item associated type is where the lifetime lands, and it is fiddly on purpose.
- Once it is an Iterator, every adaptor in std works on it for free.

## Neighbours

Previous: `../28-errors/`
Next: `../30-traits/`
