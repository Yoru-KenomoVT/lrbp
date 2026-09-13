# 11. Recover JPEGs from a card image

Tier 1: Files and bytes

## Why this one

Binary scanning. The same shape as finding a magic number in any file format.

## What it must do

- Read a raw card image in 512-byte blocks.
- A JPEG starts at a block beginning FF D8 FF Ex where x is 0-F.
- Write each photo to its own file, blocks appended until the next marker.
- The final photo runs to end of file.

## Pass criteria

8 files, byte-identical to the originals, both trap blocks rejected.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- chunked reads
- Option as state
- Drop closing files
- slices

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

- The next marker is the only signal that a photo ended.
- A variable declared inside the loop dies each iteration.

## Neighbours

Previous: `../10-caesar/`
Next: `../12-hexdump/`
