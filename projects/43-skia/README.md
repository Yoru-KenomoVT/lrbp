# 43. Draw the puppet yourself with tiny-skia

Tier 7: Graphics and UI

## Why this one

2D vector rendering with no UI framework at all. This is closest to what a 2D animation runtime actually does.

## What it must do

- Draw filled and stroked paths, gradients and transforms to a pixel buffer.
- Render a simple layered figure whose parts move with a parameter.
- Write frames out as PNG, then animate them.
- Measure per-frame cost; no allocation inside the frame loop.

## Pass criteria

Animated output renders correctly; frame timings recorded; no per-frame allocation.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- tiny-skia
- paths and transforms
- layered compositing
- allocation-free frame loops

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

- tiny-skia is pure Rust; skia-safe binds real Skia and is far harder to build. Start with tiny-skia.
- A parameter driving a transform driving a drawn part is the core of any 2D animation runtime.
- Allocate at setup, never inside the frame loop. Prove yours does not.

## Neighbours

Previous: `../42-iced/`
Next: `../44-editor/`
