# 14. Parse a delimited table

Tier 1: Files and bytes

## Why this one

String parsing with real error cases. Precursor to reading any text format.

## What it must do

- Read a TSV file, first row is headers.
- Parse into rows of typed values: integers where possible, otherwise strings.
- Report the line and column of any malformed row rather than panicking.
- Support a --column NAME flag printing just that column.

## Pass criteria

Malformed input produces a located error message; no unwrap or expect anywhere.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- custom error enum
- parse::<T>()
- lifetimes on borrowed fields
- Result chaining

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

- A row with the wrong field count is an error, not a panic.
- Borrowing from the input avoids allocating a String per cell.

## Neighbours

Previous: `../13-wc/`
Next: `../15-wav/`
