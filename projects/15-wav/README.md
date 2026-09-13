# 15. Read a WAV header

Tier 1 — Files and bytes

## Why this one

RIFF is magic + length + chunks. Structurally identical to your .aom container.

## What it must do

- Read a .wav file and print sample rate, channels, bit depth and duration.
- Validate the RIFF and WAVE magic before trusting anything.
- Walk the chunk list rather than assuming fmt comes first.
- Reject a declared chunk length that exceeds the file.

## Pass criteria

Correct values for several real WAVs; a truncated file errors instead of panicking.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- little-endian integers
- chunk walking
- bounds checking before reads
- from_le_bytes

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

- Every offset must be checked against the file length before use.
- This is the exact discipline docs/goals.md demands of the moc3 loader.

## Neighbours

Previous: `../14-tsv/`
Next: `../16-grep/`
