# 34. A JSON API with actix-web

Tier 5 — Network and services

## Why this one

Real web service shape. Useful well beyond ayatsuri2d.

## What it must do

- Expose GET and POST endpoints over JSON.
- Share application state across handlers safely.
- Return proper status codes and structured errors.
- Add integration tests hitting the routes.

## Pass criteria

Endpoints work end to end; errors map to correct status codes; tests pass.

Full rubric in `../../criteria.md`. Ask for a mark when you think it is done.

## New concepts

- actix-web
- serde derive
- extractors
- shared state
- async handlers

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

- serde derive here after hand-writing JSON earlier. You will appreciate what it saves.
- A handler returning Result lets the framework map your error type to a status code.

## Neighbours

Previous: `../33-tcp/`
Next: `../35-websocket/`
