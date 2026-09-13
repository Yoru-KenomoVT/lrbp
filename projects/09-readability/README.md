# 09. Grade reading difficulty

Tier 1 — Files and bytes

## Why this one

CS50 pset 2. Counting things in text correctly, which is harder than it sounds.

## What it must do

- Read a passage from stdin.
- Count letters, words and sentences.
- Apply the Coleman-Liau index and print the grade.
- Grades below 1 print 'Before Grade 1', 16 and above print 'Grade 16+'.

## Pass criteria

Matches the expected grade on the standard passages.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- counting with iterators
- char classification
- float maths
- rounding

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

- Defining what counts as a sentence is the whole problem. Write down your rule.
- Rust's round() may not round the way the formula expects. Check a boundary case.

## Neighbours

Previous: `../08-todo/`
Next: `../10-caesar/`
