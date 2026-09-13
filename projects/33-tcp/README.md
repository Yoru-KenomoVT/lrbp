# 33. A TCP echo server

Tier 5: Network and services

## Why this one

Sockets before frameworks. Understand what actix is doing for you.

## What it must do

- Listen on a port, accept connections, echo lines back.
- Handle multiple clients concurrently.
- Shut down cleanly on ctrl-c.
- Test it with netcat.

## Pass criteria

Handles several simultaneous clients; survives abrupt disconnects; exits cleanly.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- TcpListener
- per-connection handling
- blocking vs async
- graceful shutdown

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

- Do the blocking thread-per-connection version first, then the async one. The contrast is the lesson.
- A client that disconnects mid-write must not take the server down.

## Neighbours

Previous: `../32-fuzz/`
Next: `../34-actix/`
