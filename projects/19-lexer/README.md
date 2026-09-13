# 19. Tokenise a small expression language

Tier 2: Text and parsing

## Why this one

Turning bytes into meaning. The first half of any parser.

## What it must do

- Tokenise numbers, identifiers, + - * / ( ) and whitespace.
- Each token carries its byte offset for error reporting.
- Unknown characters produce a located error.
- Provide an iterator interface over tokens.

## Pass criteria

Round-trips a set of test inputs; every error reports a correct byte offset.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- enums with data
- implementing Iterator
- peekable
- spans

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

- A token is a kind plus a span, not just a string.
- Peeking without consuming is the core move of a lexer.

## Neighbours

Previous: `../18-speller/`
Next: `../20-parser/`
