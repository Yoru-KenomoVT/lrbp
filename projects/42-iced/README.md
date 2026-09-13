# 42. The same app in Iced

Tier 7 — Graphics and UI

## Why this one

Elm architecture: messages in, state out. A completely different model to Dioxus, and worth feeling before you commit the editor to either.

## What it must do

- Rebuild the file browser from the Dioxus project in Iced.
- Model it properly: Message enum, update, view.
- Keep feature parity, including the live filter.
- Write up which model suited the problem better, and why.

## Pass criteria

Feature parity with the Dioxus version; a written comparison of the two models.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- the Elm architecture
- Message enums
- update as a pure function
- iced::Task

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

- Every user action becomes a Message variant. Exhaustive matching means the compiler finds states you forgot.
- Dioxus reacts to signal changes; Iced processes a message queue. Notice which one you had to fight.

## Neighbours

Previous: `../41-dioxus/`
Next: `../43-skia/`
