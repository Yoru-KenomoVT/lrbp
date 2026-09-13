# 38. Benchmark the tail, not the mean

Tier 6: Systems and FFI

## Why this one

The mean hides the stutter people actually notice. Assert on the tail instead.

## What it must do

- Benchmark the hot path of an earlier project with criterion.
- Report p50, p99 and p99.9, not just the mean.
- Add a threshold that fails when the tail regresses.
- Write up why the mean is the wrong number to watch.

## Pass criteria

Benchmarks report percentiles; a deliberate regression is caught by the gate.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- criterion
- statistical benchmarking
- tail latency
- regression gates

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

- avg 4ms with p99.9 of 38ms feels broken. avg 9ms with p99.9 of 10ms feels perfect.
- Perception tracks outliers. That is the whole argument.

## Neighbours

Previous: `../37-mmap/`
Next: `../39-ratatui/`
