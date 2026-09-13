#!/usr/bin/env bash
# lrbp setup: check the toolchain, build the grader, install it on PATH.
set -euo pipefail

PREFIX="${PREFIX:-$HOME/.local}"
ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

say()  { printf '  %s\n' "$*"; }
fail() { printf '  ERROR: %s\n' "$*" >&2; exit 1; }

echo
echo "lrbp setup"
echo "=========="
echo

# --- toolchain -------------------------------------------------------------
command -v cargo >/dev/null || fail "cargo not found. Install Rust from https://rustup.rs"
command -v rustc >/dev/null || fail "rustc not found. Install Rust from https://rustup.rs"
say "rustc    $(rustc --version | awk '{print $2}')"
say "cargo    $(cargo --version | awk '{print $2}')"

command -v cc >/dev/null || command -v gcc >/dev/null \
  || fail "no C compiler found. The grader is written in C. Install gcc or clang."
say "cc       $({ cc --version || gcc --version; } 2>/dev/null | head -1)"

command -v make >/dev/null || fail "make not found."

# --- grader ----------------------------------------------------------------
echo
say "building the grader..."
make -C "$ROOT/grade" clean >/dev/null 2>&1 || true
make -C "$ROOT/grade" >/dev/null || fail "grader failed to build"
say "built    $ROOT/grade/grade"

mkdir -p "$PREFIX/bin"
install -m755 "$ROOT/grade/grade" "$PREFIX/bin/grade"
say "installed $PREFIX/bin/grade"

# --- PATH ------------------------------------------------------------------
case ":$PATH:" in
  *":$PREFIX/bin:"*) ;;
  *) echo
     say "NOTE: $PREFIX/bin is not on your PATH."
     say "Add this to your shell rc file:"
     echo
     say "    export PATH=\"\$PATH:$PREFIX/bin\""
     ;;
esac

# --- done ------------------------------------------------------------------
echo
echo "  ready."
echo
echo "    cd projects/01-hello-its-me"
echo "    cat README.md"
echo "    \$EDITOR src/main.rs"
echo "    grade"
echo
