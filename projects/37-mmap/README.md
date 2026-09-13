# 37. Memory-mapped zero-copy reads

Tier 6: Systems and FFI

## Why this one

Reading large files without copying them.

## What it must do

- Memory-map a file and parse your container from the mapped bytes.
- Return borrowed slices into the map rather than owned Vecs.
- Handle the file being truncated underneath you.
- Compare throughput against the read-based version.

## Pass criteria

Parses without copying bulk data; measured faster; unsafe blocks have a written justification.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- memmap2
- lifetimes tied to a mapping
- unsafe and its invariants
- zero-copy

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

- A borrowed slice cannot outlive the mapping. The compiler will enforce it.
- Mapping is unsafe because the file can change beneath you. Document why yours is sound.

## Neighbours

Previous: `../36-cabi/`
Next: `../38-bench/`
