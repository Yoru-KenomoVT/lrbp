# 24. Image filters on a BMP

Tier 3 — Binary and memory

## Why this one

CS50 pset 4. Pixel arrays, stride and in-place transformation. The neighbour of recover.

## What it must do

- Read a 24-bit BMP, parse both headers.
- Implement grayscale, sepia, reflect and blur.
- Write the result out as a valid BMP.
- Handle padding on each scanline correctly.

## Pass criteria

All four filters produce correct images; padding handled; output opens in an image viewer.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- 2D data in a flat buffer
- scanline padding
- in-place vs copy
- clamping

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

- BMP rows are padded to a multiple of 4 bytes. Getting stride wrong skews the image visibly.
- Blur needs the original pixels, not the ones you already changed. That decides your data flow.

## Neighbours

Previous: `../23-png/`
Next: `../25-msgpack/`
