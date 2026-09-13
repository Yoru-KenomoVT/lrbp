# 36. Expose a C ABI

Tier 6 — Systems and FFI

## Why this one

ayatsuri-capi is the load-bearing piece. Every binding depends on getting this right.

## What it must do

- Wrap the roundtrip format library in extern "C" functions.
- Use an opaque handle; callers never see Rust types.
- Return error codes, never panic across the boundary.
- Write a small C program that links and drives it.

## Pass criteria

A C program links against it and round-trips a file; no panic can escape.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- extern "C"
- #[repr(C)]
- catch_unwind
- cbindgen
- ownership across FFI

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

- A panic unwinding across the FFI boundary is undefined behaviour.
- Decide who frees what, and document it. This is the whole contract.

## Neighbours

Previous: `../35-websocket/`
Next: `../37-mmap/`
