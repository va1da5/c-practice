# Mastering C Language

## Week 1: Fundamentals and Setup

### Day 1: Setting up the environment

- Topics: Install a C compiler (e.g., GCC) and IDE/editor.
- Key Points:
  - Write and run a "Hello, World!" program.
  - Understand the compilation process (gcc commands).
  - Learn about the structure of a C program: `#include`, `main()`, and `return`.
- Practice: Write, compile, and run a program that prints a simple message.

### Day 2: Data types and variables

- Topics: Primitive types, type sizes, and the sizeof operator.
- Key Points:
  - Understand `int`, `float`, `double`, `char`, `_Bool`.
  - C types: `int8_t`, `int16_t`, etc. (from `<stdint.h>`).
- Practice: Write a program that prints the size of each type on your system.

```c
#include <stdio.h>

int main() {
  int integer_variable;
  float float_variable;
  char character_variable;
  int array_of_integers[10];

  printf("Size of int: %zu bytes\n", sizeof(int));
  printf("Size of float: %zu bytes\n", sizeof(float));
  printf("Size of char: %zu byte\n", sizeof(char));
  printf("Size of integer_variable: %zu bytes\n", sizeof(integer_variable));
  printf("Size of array_of_integers: %zu bytes\n", sizeof(array_of_integers));
  printf("Number of elements in array_of_integers: %zu\n",
         sizeof(array_of_integers) / sizeof(array_of_integers[0]));

  return 0;
}

// Size of int: 4 bytes
// Size of float: 4 bytes
// Size of char: 1 byte
// Size of integer_variable: 4 bytes
// Size of array_of_integers: 40 bytes
// Number of elements in array_of_integers: 10
```

### Day 3: Operators and expressions

- Topics: Arithmetic, logical, relational, bitwise, and assignment operators.
- Key Points:
  - Emphasize operator precedence and associativity.
  - Introduce bitwise operations (e.g., `&`, `|`, `~`, `^`, `<<`, `>>`).
- Practice: Implement a program that performs basic arithmetic and bitwise operations, displaying the results.

```c
#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char *to_bin_repr(int16_t n) {
  char *binary =
      malloc(sizeof(int16_t) * CHAR_BIT + 1); // +1 for null terminator
  int16_t size = sizeof(int16_t) * CHAR_BIT;

  for (int i = size - 1; i >= 0; i--) {
    binary[size - 1 - i] = (n & (1 << i)) ? '1' : '0';
  }
  binary[size] = '\0';
  return binary;
}

void show(int16_t a, int16_t b, int16_t c, char *operator) {
  printf("  %s (%" PRId16 ")\n%s %s (%" PRId16 ")\n= %s (%" PRId16 ")\n\n",
         to_bin_repr(a), a, operator, to_bin_repr(b), b, to_bin_repr(c), c);
}

int main() {
  int16_t a = 0b00010101;
  int16_t b = 0b00001010;
  show(a, b, a + b, "+");

  show(a, b, a - b, "-");

  b = 0b00001111;
  show(a, b, a & b, "&");

  b = 0b00001010;
  show(a, b, a | b, "|");

  b = 0b00001011;
  show(a, b, a ^ b, "^");

  b = 0b00001010;
  show(0, a, ~a, "~");

  show(0, 1, 1 << 2, " 1 << 2 ");

  show(0, 16, 16 >> 3, "16 >> 3");

  return 0;
}

//   0000000000010101 (21)
// + 0000000000001010 (10)
// = 0000000000011111 (31)

//   0000000000010101 (21)
// - 0000000000001010 (10)
// = 0000000000001011 (11)

//   0000000000010101 (21)
// & 0000000000001111 (15)
// = 0000000000000101 (5)

//   0000000000010101 (21)
// | 0000000000001010 (10)
// = 0000000000011111 (31)

//   0000000000010101 (21)
// ^ 0000000000001011 (11)
// = 0000000000011110 (30)

//   0000000000000000 (0)
// ~ 0000000000010101 (21)
// = 1111111111101010 (-22)

//   0000000000000000 (0)
//  1 << 2  0000000000000001 (1)
// = 0000000000000100 (4)

//   0000000000000000 (0)
// 16 >> 3 0000000000010000 (16)
// = 0000000000000010 (2)
```

### Day 4: Control flow - Conditional statements

- Topics: `if`, `else if`, `else`, switch-case.
- Key Points:
  - Use break and default in switch cases.
  - Discuss nested conditions.
- Practice: Write a program to classify a number as positive, negative, or zero using both if and switch.

### Day 5: Control flow - Loops

- Topics: `for`, `while`, and `do-while` loops.
- Key Points:
  - Loop syntax and use cases.
  - Difference between while and `do-while`.
- Practice: Create a program to calculate the factorial of a number using all three loop types.

### Day 6: Functions and scope

- Topics: Function declaration, definition, and usage.
- Key Points:
- Parameter passing by value.
  - Function prototypes and void.
  - Global vs local scope.
- Practice: Write a program that implements a simple calculator using functions.

### Day 7: Review and mini-project

- Topics: Review all topics covered so far.
- Practice: Implement a program that takes a list of integers as input, calculates the sum, and finds the maximum value.

---

## Week 2: Deeper into C

### Day 8: Pointers - Introduction

- Topics: Basics of pointers, `*` (dereferencing), and `&` (address-of).
- Key Points:
  - Pointer arithmetic basics.
  - Null pointers.
- Practice: Write a program to demonstrate pointer manipulation and printing addresses of variables.

### Day 9: Arrays and strings

- Topics: Array declaration, initialization, and traversal.
- Key Points:
  - Character arrays and strings.
  - Common string functions in `<string.h>` (`strlen`, `strcpy`, etc.).
- Practice: Implement a program to reverse a string using arrays.

### Day 10: Multidimensional arrays

- Topics: Declaring and using 2D arrays.
- Key Points:
  - Array indexing.
  - Applications like matrices.
- Practice: Create a program to add two 2D arrays (matrices).

### Day 11: Advanced pointers

- Topics: Pointers to arrays, functions, and dynamic memory.
- Key Points:
  - Pointer to char strings.
  - Passing pointers to functions.
- Practice: Write a program to find the largest element in an array using pointers.

### Day 12: Dynamic memory management

- Topics: `malloc`, `calloc`, `realloc`, and `free`.
- Key Points:
  - Allocating and freeing memory.
  - Avoiding memory leaks.
- Practice: Implement a program that dynamically resizes an array.

### Day 13: Structures

- Topics: Structs for grouping data.
- Key Points:
  - Nested structs and pointers to structs.
  - Using `typedef`.
- Practice: Write a program to store and display student records using structs.

### Day 14: Review and mini-project

- Topics: Review all topics covered in Week 2.
- Practice: Build a program that dynamically manages a library of books (add, delete, search records using structs and dynamic memory).

---

## Week 3: Intermediate Features

### Day 15: Input/output

- Topics: `printf`, `scanf`, `gets`, `fgets`.
- Key Points:
  - Format specifiers in `printf` and `scanf`.
  - Buffer overflows and safe input handling.
- Practice: Write a program to read and print user details safely.

### Day 16: File handling

- Topics: `fopen`, `fclose`, `fread`, `fwrite`, `fprintf`, `fscanf`.
- Key Points:
  - Reading and writing files.
  - File modes (r, w, a, etc.).
- Practice: Write a program to read a file and count the number of lines.

### Day 17: Enumerations and macros

- Topics: `enum`, `#define`, `const`, `inline`.
- Key Points:
  - Differences between `#define` and `const`.
  - Inline functions for optimization.
- Practice: Implement an enum for error codes and a macro for calculating the square of a number.

### Day 18: C99-specific features

- Topics: Mixed declarations, new data types (`_Complex`, `_Imaginary`), variable-length arrays.
- Key Points:
  - Understanding variable-length arrays (VLA).
  - Use of `<tgmath.h>`.
- Practice: Write a program to perform operations on complex numbers.

### Day 19: Advanced structures

- Topics: Unions, bitfields, and flexible array members.
- Key Points:
  - Memory-saving features of unions.
  - Practical use of bitfields.
- Practice: Create a union to manage a variable that can store different types.

### Day 20: Preprocessor directives

- Topics: `#include`, `#ifdef`, `#ifndef`, `#pragma`.
- Key Points:
  - Conditional compilation.
  - Customizing code based on compiler flags.
- Practice: Write a program that toggles debug output using preprocessor flags.

### Day 21: Review and mini-project

- Practice: Build a basic student management system that uses file handling, structs, and preprocessor directives.

---

## Week 4: Advanced Concepts

### Day 22: Function pointers

- Topics: Using pointers to functions.
- Key Points:
  - Passing functions as arguments.
- Practice: Write a program that uses a function pointer for different arithmetic operations.

### Day 23: Recursion

- Topics: Recursive function calls.
- Key Points:
  - Base and recursive cases.
  - Tail recursion.
- Practice: Implement a program to compute Fibonacci numbers recursively.

### Day 24: Linked lists

- Topics: Singly and doubly linked lists.
- Key Points:
  - Adding and deleting nodes.
- Practice: Create a program to implement a basic singly linked list.

### Day 25: Error handling

- Topics: Return codes, `errno`, and `perror`.
- Key Points:
  - Common C error handling mechanisms.
- Practice: Write a program that opens a file and handles errors appropriately.

### Day 26: Signals

- Topics: Signal handling with `signal()` and `raise()`.
- Practice: Write a program to handle `SIGINT`.

### Day 27: Concurrency with threads

- Topics: POSIX threads (`pthread`).
- Key Points:
  - Creating and joining threads.
- Practice: Write a program that spawns threads to calculate partial sums of an array.

### Day 28: Advanced algorithms

- Topics: Sorting and searching algorithms.
- Practice: Implement quicksort or binary search.

### Day 29: Final project - Part 1

- Goal: Plan and start building a larger project (e.g., a text-based game or a command-line tool).

### Day 30: Final project - Part 2

- Goal: Complete the project and review all concepts learned.
