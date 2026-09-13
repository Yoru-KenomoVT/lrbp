# 18. A spell checker with your own hash table

Tier 2 — Text and parsing

## Why this one

CS50 pset 5, the big one. Hash tables, ownership and measuring what you built.

## What it must do

- Load a dictionary into a hash table you implement yourself, not HashMap.
- Check a text file and report misspellings.
- Report load, check and unload timings.
- Compare against std's HashMap and explain the difference.

## Pass criteria

Correct misspellings on the test corpus; timings reported; written comparison to HashMap.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- hashing
- collision handling
- ownership of a large structure
- benchmarking

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

- Writing the table yourself is the point. Using HashMap is the comparison, not the answer.
- Where does the memory for 140,000 words live, and who frees it?

## Neighbours

Previous: `../17-clap/`
Next: `../19-lexer/`
