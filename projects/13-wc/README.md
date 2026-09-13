# 13. Count lines, words and bytes

Tier 1 — Files and bytes

## Why this one

Text handling and stdin. Every CLI tool you write later needs this shape.

## What it must do

- Accept zero or more file paths. With none, read stdin.
- Print line, word and byte counts per file, matching `wc` column order.
- Print a total row when given more than one file.
- Flags -l, -w, -c select individual columns.

## Pass criteria

Output matches system `wc` for ASCII and UTF-8 files, single and multiple.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- stdin vs files
- BufRead::lines
- iterator chains
- UTF-8 vs bytes

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

- A word is a run of non-whitespace. split_whitespace already defines this.
- Byte count is not character count. Decide which `wc` reports.

## Neighbours

Previous: `../12-hexdump/`
Next: `../14-tsv/`
