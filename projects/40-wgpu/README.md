# 40. Draw a triangle with wgpu

Tier 7: Graphics and UI

## Why this one

Every renderer needs a GPU pipeline. Start where every graphics tutorial starts.

## What it must do

- Open a window and clear it to a colour.
- Draw a single triangle with a vertex and fragment shader.
- Move the vertices into a vertex buffer.
- Resize correctly without leaking surfaces.

## Pass criteria

A triangle renders, resizing is clean, pipeline creation happens once.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- wgpu
- WGSL shaders
- render pipelines
- surface configuration

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

- Pipelines are built at load. A shader compile mid-frame is a 10-100ms stall.
- That starts mattering the moment you have more than one pipeline.

## Neighbours

Previous: `../39-ratatui/`
Next: `../41-dioxus/`
