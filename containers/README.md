# STL: containers
This section of the library contains useful data-storage containers as of 11 Jun, this folder contains the following implementations:
- Doubly Linked Lists (as `List`)
- Singly Linked Lists (as `FwdList`)
- Fixed-sized Array Wrapper (as `Array`)
- Dynamically-resizing Array wrapper (as `Vector`)
- Queue (FIFO) structure (as `Queue`)
- Stack (LIFO) structure (as `Stack`)
- String of character with resizing capabilties (as `String`)

With each container (apart from Queue's and Stack's, since I don't see how iterating over a controlled output structure is ever desirable) comes two types of iterators, `Iterator` & `ConstIterator` (the former allowing for mutating the element it's pointing to, the latter otherwise).

All code in this library is located in namespace `salih::containers`.
