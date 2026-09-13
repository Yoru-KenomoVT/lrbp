# 12. hexdump -C in Rust

Tier 1: Files and bytes

## Why this one

The tool you will reach for constantly once you are reading binary formats.

## What it must do

- Take one file path argument.
- Print offset (8 hex digits), 16 hex bytes with an extra space after the 8th, then printable ASCII in | bars.
- Bytes 0x20..=0x7E print as themselves, everything else as a dot.
- Pad the hex column on a short final row so the bars stay aligned.

## Pass criteria

diff against `hexdump -C FILE | head -n -1` is clean for small.bin and card.raw.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- command line arguments
- byte classification
- column alignment
- stderr and exit codes

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

- Work out how many characters one missing byte costs in the hex column.
- The extra mid-row space counts toward the padding too.

## Neighbours

Previous: `../11-recover/`
Next: `../13-wc/`
