# Email: yuvali532@gmail.com

# MyContainer Project

## Overview

This project implements a custom container class named `MyContainer` in C++, along with several specialized iterators that allow traversal of the container’s elements in different orders. The main iterators include:

- **AscendingOrderIterator** — iterates elements in ascending order.
- **DescendingOrderIterator** — iterates elements in descending order.
- **SideCrossOrderIterator** — iterates elements starting from the sides moving inward.
- **ReverseOrderIterator** — iterates elements in reverse order.
- **OrderIterator** — a base iterator class.
- **MiddleOutIterator** — iterates elements starting from the middle and moving outward.

The implementation uses templates, allowing `MyContainer` to work with various data types such as `int`, `double`, and `std::string`.

---

## Key Features

- **Custom Iterators** with support for increment (`++`), comparison (`==` and `!=`), and dereference (`*`) operators.
- **Exception Handling** — robust checks to handle invalid operations such as dereferencing invalid iterators or incrementing beyond the container's limits.
- **Memory Management** — no memory leaks, verified with Valgrind.
- **Testing** — comprehensive unit tests using the Doctest framework covering all iterator types and core container functionalities.
- **Friend Keyword Usage** — The `friend` keyword is used to allow iterator classes to access the private members of `MyContainer`. This enables the iterators to directly interact with the internal data structures of the container, such as accessing the underlying storage of elements, which is necessary for efficient iteration and manipulation without exposing these details publicly.

---

## Building and Running the Project

This project includes a `Makefile` to simplify compilation, testing, memory checking, and cleaning.

- To **compile and run the demonstration program**, use:
  ```
  make Main
  ```
  This command compiles the `main.cpp` source file into an executable named `run` and immediately runs it. It shows how to use the `MyContainer` class and its iterators in practice.

- To **compile and run the unit tests**, use:
  ```
  make test
  ```
  This compiles the `test.cpp` file (which contains all unit tests) into an executable named `test` using the Doctest testing framework. After compiling, it runs the tests and outputs the results.

- To **check for memory leaks** in the demonstration program, use:
  ```
  make valgrind
  ```
  This target first builds and runs the demo executable (`run`), then runs it through `valgrind` with full leak detection enabled. This helps ensure that there are no memory leaks or invalid memory accesses in the program.

- To **clean the project directory**, removing all compiled files and executables, use:
  ```
  make clean
  ```
  This deletes object files (`*.o`), the demo executable (`run`), and the test executable (`test`), allowing you to start fresh before recompiling.

---

## Testing

All unit tests are written using the Doctest framework. The tests cover:

- All iterator classes for multiple data types (`int`, `double`, `std::string`).
- Iterator operations: increment, comparison, dereference.
- Exception safety for invalid operations.
- Container insertion and removal operations.

Running `make test` compiles and executes these tests, showing detailed results.

---
