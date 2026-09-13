# 23. Walk PNG chunks

Tier 3 — Binary and memory

## Why this one

A real, hostile-input binary format with length-prefixed chunks and checksums.

## What it must do

- Validate the 8-byte PNG signature.
- Walk every chunk: length, type, data, CRC32.
- Verify each CRC and report mismatches.
- Print image width, height, bit depth and colour type from IHDR.

## Pass criteria

Correct dimensions for several PNGs; a corrupted CRC is detected and reported.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- big-endian integers
- CRC32
- length-prefixed records
- rejecting hostile input

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

- PNG is big-endian. WAV was little-endian. Read the spec, not your assumptions.
- A declared length larger than the remaining file is an attack, not a bug.

## Neighbours

Previous: `../22-json/`
Next: `../24-filter/`
