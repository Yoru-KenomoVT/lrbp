# 08. A to-do list that survives restarts

Tier 0: On-ramp

## Why this one

Vec, ownership and simple persistence. Your first program with state on disk.

## What it must do

- add, list, done and remove commands.
- Items persist to a plain text file between runs.
- Listing shows an index and a done marker.
- An index that does not exist is an error, not a panic.

## Pass criteria

Items survive a restart; an out-of-range index errors cleanly.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- Vec<T>
- borrowing from a collection
- reading and writing a whole file
- enumerate

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

- Deciding the file format is the actual design work here. Keep it boring.
- An index from a user is untrusted input. Check it before you use it.

## Neighbours

Previous: `../07-units/`
Next: `../09-readability/`
