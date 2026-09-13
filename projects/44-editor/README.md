# 44. Dioxus shell around a wgpu viewport

Tier 7 — Graphics and UI

## Why this one

The actual shape of the ayatsuri editor: UI chrome around a live render surface.

## What it must do

- Embed a wgpu-rendered viewport inside a Dioxus window.
- UI controls drive uniforms the shader reads.
- Render only when something changed, not every frame unconditionally.
- Load a file through the UI and show parsed information beside the viewport.

## Pass criteria

UI and viewport coexist, controls affect the render, idle CPU stays low.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- integrating a renderer with a UI framework
- event loop ownership
- redraw scheduling

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

- Who owns the event loop is the hard question. Answer it deliberately.
- Rendering on demand rather than continuously is what keeps a laptop cool.

## Neighbours

Previous: `../43-skia/`
This is the last project. Go build ayatsuri2d.
