# 25. MessagePack encode and decode

Tier 3 — Binary and memory

## Why this one

The .aom payload format. This is ayatsuri_format's serialisation layer, built by hand.

## What it must do

- Encode and decode integers, strings, arrays, maps and bin blobs.
- Handle the compact single-byte forms as well as the sized ones.
- Round-trip a nested structure byte-identically.
- Reject truncated input at every length prefix.

## Pass criteria

Round-trips nested data byte-identically; truncation rejected at every prefix.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- variable-length encoding
- tag bytes
- bin vs str
- exhaustive rejection

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

- docs/aom-format.md says bulk arrays are bin, never lists. Now you will see why.
- Every length prefix is an opportunity for a hostile file to lie to you.

## Neighbours

Previous: `../24-filter/`
Next: `../26-roundtrip/`
