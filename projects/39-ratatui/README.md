# 39. A terminal UI

Tier 7 — Graphics and UI

## Why this one

The fourth way to build a UI, and the cheapest to run. A TUI model inspector is a real tool for ayatsuri2d.

## What it must do

- Build a two-pane terminal app: a file list and a hex view.
- Reuse your hexdump crate for the right-hand pane.
- Scrolling, keyboard navigation and a live filter.
- Restore the terminal correctly on quit, on error AND on panic.

## Pass criteria

Navigates and filters; terminal is restored after a forced panic; idle CPU near zero.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- ratatui
- raw mode and alternate screen
- event loops
- panic hooks
- terminal restoration

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

- A TUI that panics in raw mode leaves the user's terminal unusable. Install a panic hook that restores it first.
- Redraw only on an event, not in a busy loop. A TUI spinning at 100% CPU is a bug.
- This is the same file-browser problem as the Dioxus and Iced projects. Four models, one problem.

## Neighbours

Previous: `../38-bench/`
Next: `../40-wgpu/`
