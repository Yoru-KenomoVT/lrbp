# 41. A Dioxus desktop app

Tier 7: Graphics and UI

## Why this one

A desktop UI. Components, state and events before any of it is load bearing.

## What it must do

- Build a desktop app listing files from a folder.
- Selecting one shows its hex dump, reusing project 02.
- Add a filter box that narrows the list as you type.
- Keep state in signals, not globals.

## Pass criteria

App runs, filter is live, hex view updates on selection, no panics.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- Dioxus components
- rsx!
- signals and reactivity
- desktop renderer

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

- Reactivity means you describe what the UI IS, not what to change.
- Reuse your own hexdump crate. That is the point of crate boundaries.

## Neighbours

Previous: `../40-wgpu/`
Next: `../42-iced/`
