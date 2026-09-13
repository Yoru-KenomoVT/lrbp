# 17. Give a tool a real CLI

Tier 2: Text and parsing

## Why this one

You have hand-rolled argument parsing five times by now. See what a real CLI framework saves, and what it costs.

## What it must do

- Rebuild the grep or hexdump interface using clap's derive API.
- Add subcommands, short and long flags, defaults and value validation.
- Generated --help and --version must be correct and readable.
- Support an environment-variable fallback and generate shell completions.

## Pass criteria

Full feature parity with the hand-rolled version; --help is genuinely useful; completions generate.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- clap derive
- subcommands
- argument validation
- generated help
- shell completions

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

- Compare the derive version against your hand-rolled one. Count the lines and the bugs.
- A struct with attributes IS the interface. Getting the type right does the validation for you.
- Generated help is only good if your doc comments are. Write them properly.

## Neighbours

Previous: `../16-grep/`
Next: `../18-speller/`
