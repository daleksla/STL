# STL
Common algorithms & structural implementations of the C++'s standard library, rewritten to be small, portable, and fast

## Summarising

This library is a reimplementation of C++'s more common algorithms & structural implementations (e.g. std::vector -> stl::vector, etc.), with a key focus on:
1. Rewriting code to take up little space in memory
2. Writing *all* code to be compiled & ran for a C++11 compiler (even if the features were inspired from a later standard)
3. Speed

Notes:
- This project is **not** concerned with replacing the general-use, feature-rich tried-and-tested C++ STL. If you want something fast & small, have very specific compiler requirements, and don't require lucrative features of C++ (e.g. filesystem libraries) then this is for you
- The threading / concurrency library is **not** included due to the scoping issues it would present to this project (e,g. aspects such as atomics are hardware dependant)
- This is **not** focussed on reimplementing the C standard libraries which C++ happens to wrap (e.g. malloc -> ~~stl::malloc~~)
- This library also will **not** deal with exception handling
  - Note: I use exception handling in my other works and I prefer much more to error-codes (in fact [this wrapper around POSIX standard functions](https://github.com/daleksla/posicxx) creates wrappers around all the system calls which utilise C++ exceptions. But that library was written for convinient error-checking with minimal overhead, a different purpose to this library's.

## Building

Since virtually the entire library uses (static) polymorphism and template meta-programming, attempting to provide a library file is pointless. It is therefore *header-only* and the library *does not* require explicit compilation

[![Clang](https://github.com/daleksla/STL/actions/workflows/clang.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/clang.yml) [![GCC](https://github.com/daleksla/STL/actions/workflows/gcc.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/gcc.yml) [![Testing](https://github.com/daleksla/STL/actions/workflows/testing.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/testing.yml)

## Using

You will need to include the relevant headers as you would for C++'s STL alternatives

For example:

#include <vector>

...is now...

#include <vector.hpp>

Refer to documentation for usage of each function / class.

*** 

(c) Salih Mahmoud Sayed Ahmed, 2021. All rights reserved. See LICENSE for terms on code usage
