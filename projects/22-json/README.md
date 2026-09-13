# 22. Parse JSON by hand

Tier 2: Text and parsing

## Why this one

Recursive descent on a self-describing format. Most application config and model files are JSON.

## What it must do

- Parse the full JSON grammar into an enum value type.
- Handle nesting, escapes and numbers correctly.
- Report the byte offset of any syntax error.
- Add a pretty-printer that round-trips.

## Pass criteria

Parses a real-world JSON file; round-trips byte-identically; malformed input reports an offset.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- recursive enums
- escape sequences
- grammar as code
- round-trip testing

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

- Point it at a real JSON file from an application you use. Real input finds bugs synthetic input does not.
- The escape rules are where hand-written JSON parsers usually break. Test them.

## Neighbours

Previous: `../21-interpreter/`
Next: `../23-png/`
