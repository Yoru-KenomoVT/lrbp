# 35. A WebSocket server

Tier 5: Network and services

## Why this one

Live bidirectional messaging. Most desktop applications that expose a live API do it over WebSocket.

## What it must do

- Accept WebSocket connections and echo messages.
- Broadcast a message from one client to all others.
- Handle disconnects without leaking sessions.
- Write a small client that drives it.

## Pass criteria

Multiple clients connect and receive broadcasts; disconnects are cleaned up.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- the WebSocket handshake
- framing
- broadcast channels
- session lifecycle

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

- You have almost certainly used a WebSocket client. Now write the server half.
- Tracking connected clients is a shared-state problem. You solved that in the threads project.

## Neighbours

Previous: `../34-actix/`
Next: `../36-cabi/`
