# lrbp: Learn Rust By Practice

**44 projects. You build, it grades.**

Rustlings hands you a broken program and one hole to fill. That teaches you to
read compiler errors, which is useful, but it is not the same as writing
software. Every project here starts from an empty file.

Each one ships with a spec, pass criteria, a hints file, and automated checks.
Run `grade` and find out.

```
cd projects/01-hello-its-me
cat README.md
$EDITOR src/main.rs
grade
```

```
01-hello-its-me
  PASS  greets the name given
  PASS  no stray blank line
  FAIL  trims surrounding whitespace    got "Hello,   Yoru", wanted "Hello, Yoru"
  PASS  survives empty input
  PASS  exits cleanly
  5/6
```

---

## Setup

```bash
git clone https://github.com/Yoru-KenomoVT/lrbp.git && cd lrbp
./setup.sh
```

Needs a Rust toolchain ([rustup.rs](https://rustup.rs)), a C compiler and make.
`setup.sh` builds the grader and installs it to `~/.local/bin/grade`.

---

## How grading works

`grade` with no arguments grades whatever project directory you are standing
in. It finds the repo root by walking up, so it works from anywhere inside.

```bash
grade                     # the project you are in
grade 02-credit           # a specific one
grade all                 # everything with checks
```

Every run forces a full rebuild and deletes the old binary first, so a stale
artefact can never be graded by accident. If the build fails you get the real
compiler output, and `0/N (nothing ran)` rather than a misleading score.

Checks are plain C structs in [`grade/checks.h`](grade/checks.h). Adding one is
a table row. Contributions of check tables for projects that lack them are very
welcome.

---

## Marking

The automated checks cover correctness. The full rubric in
[`criteria.md`](criteria.md) covers six categories, correctness, safety, memory,
idiom, structure and tests, plus a separate **authorship** line:

    WROTE IT      you typed it
    GUIDED        you typed it after being told what was wrong
    CO-WRITTEN    the approach was yours, some of the code was not
    HANDED OVER   it was written for you

A project can score 6/6 and still be HANDED OVER. That is a pass for the code
and not for you, and the rubric says so plainly. If you are using an AI
assistant on this, that distinction is the entire point.

---

## The ladder

### Tier 0: On-ramp

*Meet the syntax. Several of these are classic C exercises.*

| # | project | what it teaches |
|---|---------|-----------------|
| 01 | [`01-hello-its-me`](projects/01-hello-its-me/) | Prove the toolchain works and meet the syntax. Deliberately almost free. |
| 02 | [`02-credit`](projects/02-credit/) | Your CS50 credit pset in Rust. Pure arithmetic and control flow, no I/O to trip over. |
| 03 | [`03-mario`](projects/03-mario/) | CS50 pset 1. Nested loops and getting the arithmetic of alignment right. |
| 04 | [`04-guessing-game`](projects/04-guessing-game/) | The classic first Rust program. Input, loops, matching and error handling in one. |
| 05 | [`05-fizz`](projects/05-fizz/) | Control flow and functions. Then the same thing as an iterator chain. |
| 06 | [`06-scrabble`](projects/06-scrabble/) | CS50 pset 2. Character arithmetic and lookup tables. |
| 07 | [`07-units`](projects/07-units/) | Arguments, floats and rejecting nonsense. The smallest real CLI tool. |
| 08 | [`08-todo`](projects/08-todo/) | Vec, ownership and simple persistence. Your first program with state on disk. |

### Tier 1: Files and bytes

*Read bytes off disk without crashing.*

| # | project | what it teaches |
|---|---------|-----------------|
| 09 | [`09-readability`](projects/09-readability/) | CS50 pset 2. Counting things in text correctly, which is harder than it sounds. |
| 10 | [`10-caesar`](projects/10-caesar/) | CS50 pset 2. Character arithmetic with wraparound, and your first key validation. |
| 11 | [`11-recover`](projects/11-recover/) | Binary scanning. The same shape as finding a magic number in any file format. |
| 12 | [`12-hexdump`](projects/12-hexdump/) | The tool you will reach for constantly once you are reading binary formats. |
| 13 | [`13-wc`](projects/13-wc/) | Text handling and stdin. Every CLI tool you write later needs this shape. |
| 14 | [`14-tsv`](projects/14-tsv/) | String parsing with real error cases. Precursor to reading any text format. |
| 15 | [`15-wav`](projects/15-wav/) | RIFF is magic + length + chunks, the shape most binary containers take. |

### Tier 2: Text and parsing

*Turn text into meaning. Ends with a working interpreter.*

| # | project | what it teaches |
|---|---------|-----------------|
| 16 | [`16-grep`](projects/16-grep/) | The classic build-a-tool exercise. Reading, matching and reporting, with real ergonomics. |
| 17 | [`17-clap`](projects/17-clap/) | You have hand-rolled argument parsing five times by now. See what a real CLI framework saves, and what it costs. |
| 18 | [`18-speller`](projects/18-speller/) | CS50 pset 5, the big one. Hash tables, ownership and measuring what you built. |
| 19 | [`19-lexer`](projects/19-lexer/) | Turning bytes into meaning. The first half of any parser. |
| 20 | [`20-parser`](projects/20-parser/) | The second half of a parser. Recursion, precedence, and enums that hold themselves. |
| 21 | [`21-interpreter`](projects/21-interpreter/) | A working language. Crafting Interpreters is the book for this and it is free online. |
| 22 | [`22-json`](projects/22-json/) | Recursive descent on a self-describing format. Most application config and model files are JSON. |

### Tier 3: Binary and memory

*Design a binary format, then defend it against hostile input.*

| # | project | what it teaches |
|---|---------|-----------------|
| 23 | [`23-png`](projects/23-png/) | A real, hostile-input binary format with length-prefixed chunks and checksums. |
| 24 | [`24-filter`](projects/24-filter/) | CS50 pset 4. Pixel arrays, stride and in-place transformation. The neighbour of recover. |
| 25 | [`25-msgpack`](projects/25-msgpack/) | A compact binary serialisation format, implemented by hand. |
| 26 | [`26-roundtrip`](projects/26-roundtrip/) | Writing a format, not just reading one. Reader and writer designed together. |
| 27 | [`27-soa`](projects/27-soa/) | The memory layout real-time systems are built on. Measure why it matters. |
| 28 | [`28-errors`](projects/28-errors/) | Production code should not be able to crash on bad input. Learn the alternative to unwrap. |

### Tier 4: Abstraction and proof

*Make correctness provable instead of hoped for.*

| # | project | what it teaches |
|---|---------|-----------------|
| 29 | [`29-iterator`](projects/29-iterator/) | Your chunk reader and token stream both want to be iterators. |
| 30 | [`30-traits`](projects/30-traits/) | The C ABI forces this decision. Understand the trade before it is load bearing. |
| 31 | [`31-threads`](projects/31-threads/) | Fearless concurrency, and finding out what the borrow checker was for all along. |
| 32 | [`32-fuzz`](projects/32-fuzz/) | A parser is only as safe as the inputs someone tried to break it with. |

### Tier 5: Network and services

*Talk over a socket.*

| # | project | what it teaches |
|---|---------|-----------------|
| 33 | [`33-tcp`](projects/33-tcp/) | Sockets before frameworks. Understand what actix is doing for you. |
| 34 | [`34-actix`](projects/34-actix/) | Real web service shape, and the most transferable skill in this tier. |
| 35 | [`35-websocket`](projects/35-websocket/) | Live bidirectional messaging. Most desktop applications that expose a live API do it over WebSocket. |

### Tier 6: Systems and FFI

*Talk to C, to memory, and to a clock.*

| # | project | what it teaches |
|---|---------|-----------------|
| 36 | [`36-cabi`](projects/36-cabi/) | A C ABI is how a Rust library reaches every other language. Get it wrong and nothing can embed it. |
| 37 | [`37-mmap`](projects/37-mmap/) | Reading large files without copying them. |
| 38 | [`38-bench`](projects/38-bench/) | The mean hides the stutter people actually notice. Assert on the tail instead. |

### Tier 7: Interfaces

*Put it on a screen. Four different ways, then choose.*

| # | project | what it teaches |
|---|---------|-----------------|
| 39 | [`39-ratatui`](projects/39-ratatui/) | The fourth way to build a UI, and by far the cheapest to run. |
| 40 | [`40-wgpu`](projects/40-wgpu/) | Every renderer needs a GPU pipeline. Start where every graphics tutorial starts. |
| 41 | [`41-dioxus`](projects/41-dioxus/) | A desktop UI. Components, state and events before any of it is load bearing. |
| 42 | [`42-iced`](projects/42-iced/) | Elm architecture: messages in, state out. A completely different model to Dioxus, and worth feeling before you commit the editor to either. |
| 43 | [`43-skia`](projects/43-skia/) | 2D vector rendering with no UI framework at all. This is closest to what a 2D animation runtime actually does. |
| 44 | [`44-editor`](projects/44-editor/) | The shape of a real editor: UI chrome wrapped around a live render surface. |

---

## Why this order

It is ordered by dependency, not theme. Project 27 assumes 22. Project 44
assumes 39 through 43.

Several early projects are classic C exercises: Luhn validation, a pyramid,
Caesar cipher, word scoring, recovering JPEGs from a disk image. If you already
wrote those in C, doing them again in Rust means you know the algorithm and can
spend all your attention on the language.

The later tiers are not padding. A C ABI, memory mapping, tail-latency
benchmarking and four separate interface models are what you need the day you
want a Rust library other languages can embed, that reads large files without
copying them, that does not stutter, and that has a front end. That is why the
ladder ends there rather than at "build a todo app".

---

## Licence

MIT. See [`LICENSE`](LICENSE).
