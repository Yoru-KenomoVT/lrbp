# 28. Typed errors, zero panics

Tier 3: Binary and memory

## Why this one

Production code should not be able to crash on bad input. Learn the alternative to unwrap.

## What it must do

- Take the WAV or PNG reader and remove every unwrap and expect.
- Define an error enum with a variant per failure mode, carrying context.
- Implement Display and std::error::Error.
- Add a lint attribute that makes panicking constructs a compile error.

## Pass criteria

No unwrap/expect/panic remains; the deny attribute is in place and the crate builds.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- error enums
- Display
- source chains
- #![deny] lints

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

- An error should say what was expected, what was found, and where.
- TooNew(version) for a flags problem is the bug your own checklist flagged.

## Neighbours

Previous: `../27-soa/`
Next: `../29-iterator/`
