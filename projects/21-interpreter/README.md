# 21. Evaluate the tree

Tier 2 — Text and parsing

## Why this one

A working language. Crafting Interpreters is the book for this and it is free online.

## What it must do

- Walk the AST and produce a value.
- Support variables, assignment and a print statement.
- Add a REPL reading a line at a time.
- Division by zero and undefined variables are runtime errors, not panics.

## Pass criteria

REPL evaluates expressions and variables; both error classes reported without panicking.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- tree walking
- environments and scope
- runtime vs parse errors
- HashMap for bindings

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

- Scope is a stack of maps. Entering a block pushes, leaving pops.
- Read Crafting Interpreters alongside this. It is in Java and C, and the ideas port directly.

## Neighbours

Previous: `../20-parser/`
Next: `../22-json/`
