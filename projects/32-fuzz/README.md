# 32. Fuzz your parser

Tier 4: Abstraction and proof

## Why this one

A parser is only as safe as the inputs someone tried to break it with.

## What it must do

- Set up cargo-fuzz against your PNG or WAV reader.
- Run until it finds a crash, or argue why it cannot.
- Add every crashing input to a regression test corpus.
- Fix each crash without weakening the parser.

## Pass criteria

Fuzzer runs clean for a sustained period; every crash found has a regression test.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- cargo-fuzz
- property testing
- corpus management
- adversarial input

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

- A fuzzer finds what you did not think of. That is the entire value.
- Most parser CVEs exist because nobody fuzzed the parser.

## Neighbours

Previous: `../31-threads/`
Next: `../33-tcp/`
