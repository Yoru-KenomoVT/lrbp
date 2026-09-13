# 26. Design and implement a binary format

Tier 3: Binary and memory

## Why this one

Writing a format, not just reading one. Reader and writer designed together.

## What it must do

- Define a container: magic, u16 version, u16 flags, u32 payload length.
- Serialise a struct of mixed fields into it and read it back.
- Reject bad magic, future versions, unknown flags and length mismatch.
- Write tests for every rejection path.

## Pass criteria

Round-trip is byte-identical; five rejection tests pass; no panics on malformed input.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- symmetric read and write
- to_le_bytes
- invariants
- rejection tests

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

- If reading and writing are not written together, they will drift.
- Write the layout down as a table before you code it. That table is your spec.

## Neighbours

Previous: `../25-msgpack/`
Next: `../27-soa/`
