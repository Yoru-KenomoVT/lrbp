# 31. Threads, channels and shared state

Tier 4 — Abstraction and proof

## Why this one

Fearless concurrency, and finding out what the borrow checker was for all along.

## What it must do

- Split work across threads with std::thread.
- Pass results back over a channel.
- Share a counter with Arc<Mutex<T>> and explain why it needs both.
- Show a version the compiler rejects, and say why it was right to.

## Pass criteria

Parallel version measurably faster; a written explanation of one rejected program.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- thread::spawn
- channels
- Arc and Mutex
- Send and Sync

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

- The data race the compiler stops is the whole point. Find one and write it up.
- Arc is shared ownership, Mutex is exclusive access. You usually need both, for different reasons.

## Neighbours

Previous: `../30-traits/`
Next: `../32-fuzz/`
