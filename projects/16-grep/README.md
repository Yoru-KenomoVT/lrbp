# 16. Search files for a pattern

Tier 2 — Text and parsing

## Why this one

The classic build-a-tool exercise. Reading, matching and reporting, with real ergonomics.

## What it must do

- Take a pattern and one or more file paths.
- Print matching lines prefixed with filename and line number.
- Support -i for case-insensitive and -v for inverted matching.
- With no files, read stdin.

## Pass criteria

Matches system grep for these flags on the test corpus; handles stdin.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- string searching
- command-line flags
- BufRead::lines
- borrowing lines

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

- Do not read the whole file. Lines arrive one at a time for a reason.
- Case-insensitive matching without allocating a lowercase copy per line is the interesting version.

## Neighbours

Previous: `../15-wav/`
Next: `../17-clap/`
