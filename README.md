# Google Code Jam Solutions

This repository contains solutions to Google Code Jam problems.

## Architecture

The solutions are built upon a simple C++ framework that handles the boilerplate
of reading the input file and writing the output file. Each problem is solved
in its own class that inherits from the `Problem` base class.

### `Problem` Class

The `Problem` class is the base class for all problem solutions. It provides
the following functionality:

* Reads the number of test cases from the input file.
* Iterates over the test cases.
* For each test case, it calls the `readProblem()` and `solveProblem()` methods.
* Writes the output of each test case to the output file.

A concrete problem implementation must inherit from this class and implement
the following methods:

* `readProblem()`: Reads the input for a single test case.
* `solveProblem()`: Solves a single test case.

### `MagicTrick` Class

The `MagicTrick` class is a solution to the
[Magic Trick](https://code.google.com/codejam/contest/2974486/dashboard#s=p0)
problem from the 2014 qualification round.

## Building and Running

To build and run the solutions, you will need a C++ compiler. The following
commands will build and run the `MagicTrick` solution:

```bash
g++ -std=c++11 -o MagicTrick Main.cpp Problem.cpp MagicTrick.cpp
./MagicTrick
```

This will create an output file named `MagicTrick-small.out` that contains the
solution to the small input set.
