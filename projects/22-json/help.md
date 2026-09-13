# Help — Parse JSON by hand

## Concepts introduced here

- recursive enums
- escape sequences
- grammar as code
- round-trip testing

## Documentation

- [JSON spec](https://www.json.org/json-en.html)

## Always useful

- [The Book](https://doc.rust-lang.org/book/)
- [The Book, interactive with quizzes](https://rust-book.cs.brown.edu/)
- [Rust by Example](https://doc.rust-lang.org/rust-by-example/)
- [std docs](https://doc.rust-lang.org/std/)
- [Playground](https://play.rust-lang.org/)

## When you are stuck

Work in this order. Most of it does not need another person.

1. **Read the whole error.** Rust errors name the file, line, column and often
   the fix. The `help:` line is frequently the answer verbatim.
2. **`cargo check`** rather than `cargo build`. Faster, same errors.
3. **`cargo clippy`.** It explains unidiomatic code, not just broken code.
4. **Shrink it.** Delete code until the error disappears, then add back.
5. **Print the values you are testing.** "It never matches" almost always means
   the condition is wrong, not the plumbing.

## Errors you will probably hit

- `cannot use the ? operator in a function that returns ()` — the function needs
  to return `Result` so the error has somewhere to go.
- `expected &[u8], found [u8; N]` — an array is not a slice. Borrow it.
- `no method named X found` — the trait is probably not in scope. `use std::io::Read;`
- `borrow of moved value` — something took ownership. Did you mean to borrow?
- `unclosed delimiter` — run `cargo fmt`; misaligned indentation makes it obvious.

## Asking for a mark

Say you are done and it gets marked against `../../criteria.md`. Partial work is
fine to submit; the mark shows where the gaps are.
