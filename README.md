# STL
Salih's Template Library (STL) is a custom C++ Library inspired by THE STL (C++'s standard template library), Boost, Common Algorithms / Data structures &amp; Python abstraction.

This project was based with 4 things in mind:
1. **Portability, compatibility** - this library is designed to maximise the availibility of it's features on any platform, on any compiler from C++11 onwards (note that obviously features such as concepts, transient memory allocation etc. are restricted to the CXX standard a given compiler follows).

2. **The programmer knows what he's doing** - a given programmer selects the correct tools, algorithms, etc. for a given job. He should be aware of the costs for a given operation. 
> For example, indexing a linked list in other libraries involves advancing a given iterator x positions with a minimum cost of O(n) time - in many cases, it's more legible and convinient to use the index operator ( `[]` ) instead, even if the latter operator now implies different costs depending on the circumstances used - the programmer should already know this! (not to mention I can issue optimisations a normal programmer would not do on a repetitive basis).

3. **Interface, interface, interface** - coming somewhat off the last point, it is important that a user can interact and understand what, why and how things are the way they are. This is reflected from useful, concise compiler error messages, to even whether a given class is given capital letters or not (I lost hours of sleep over both).

4. **Problems => Solutions** - nearly this entire library was created simply because I wanted certain features to exist / be improved upon, such as better string handling, cleaner syntax (none of this `*std::advance(list.begin(), 5)` business), list additions, etc.. (Also I wanted a learning experience and bloody hell did I get one).

***

Note: this project serves as a hobby to explore into themes such as (dynamic) memory allocation, memory management, copy / move semantics, operator overloads, polymorphism etc.. It is not officially concerned with replacing any tried-and-tested features of C++ STL (though whether some features are better or not is up to personal discretion - I do have list slicing and some nicer string handling features, which people tend to always want to use so...). 

Regardless, my code a) is a lot more legible and I encourage you to read it and understand how it works b) basically runs exactly the same as the STL versions (with regards to memory, heap allocations and the like) - no downside to usage or experimentation! 

See each sub-folder's README files for further details.

(c) Salih Mahmoud Sayed Ahmed, 2021. All rights reserved. See LICENSE for terms on code usage

[![Clang](https://github.com/daleksla/STL/actions/workflows/clang.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/clang.yml) [![GCC](https://github.com/daleksla/STL/actions/workflows/gcc.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/gcc.yml) [![Testing](https://github.com/daleksla/STL/actions/workflows/testing.yml/badge.svg)](https://github.com/daleksla/STL/actions/workflows/testing.yml)
