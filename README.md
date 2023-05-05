# C Programming Language Notes

This repository contains personal notes on learning the C programming language.

## Initial Setup

```bash
# for Fedora
dnf install gcc-c++ gdb clang-tools-extra
```

## Quick Reference

### Data Types

```c
#include <stdio.h>
#include <stdbool.h>                          // bool
#include <stdint.h>                           // int8_t,..
#include <wchar.h>                            // wchar_t

bool x = true;                                // 1 byte, values 0, 1
char a = 'a';                                 // 1 byte, values -127 to 127 or 0 to 255, usually 8 bit character
unsigned char b = 0xff;                       // 1 byte, values 0 to 255
signed char c = -1;                           // 1 byte, values -127 to 127
int d = 1234;                                 // 4 bytes, values -2147483648 to 2147483647
unsigned int e = 1;                           // 4 bytes, values 0 to 4294967295
signed int f = -127;                          // 4 bytes, values -2147483648 to 2147483647
short int g = -256;                           // 2 bytes, values -32768 to 32767
unsigned short int h = 65'535;                // 2 bytes, values 0 to 65,535
signed short int i = 32'767;                  // 2 bytes, values -32768 to 32767
long int j = 0xffffffffffffffL;               // 8 bytes, values -9223372036854775808 to 9223372036854775807
signed long int k = -0xffffffffffffff;        // 8 bytes, values -9223372036854775808 to 9223372036854775807
unsigned long int l = 0xffffffffffffffffUL;   // 8 bytes, values 0 to 18446744073709551615
long long int m = -0xfffffffffffffff;         // 8 bytes, values -(2^63) to (2^63)-1
unsigned long long int n = 0xfffffffffffffff; // 8 bytes, 0 to 18,446,744,073,709,551,615
float o = 2.5;                                // 4 bytes, single precision real (never unsigned)
double p = 3.14;                              // 8 bytes, double precision real (never unsigned)
long double q = 6.62607015e-34;               // 12 bytes
wchar_t r = L'ם';                             // 2 or 4 bytes, values 1 wide character

int8_t s = 0x7f;                              // 1 byte, values -127 to 127
int16_t t = 0x7fff;                           // 2 bytes, values -32768 to 32767
int32_t u = 0x7fffffff;                       // 4 bytes, values -2147483648 to 2147483647
int64_t v = 0x7fffffffffffffff;               // 8 bytes, values -9223372036854775808 to 9223372036854775807

uint8_t us = 0xff;                            // 1 byte, values 0 to 255
uint16_t ut = 0xffff;                         // 2 bytes, values 0 to 65,535
uint32_t uu = 0xffffffff;                     // 4 bytes, values 0 to 4294967295
uint64_t uv = 0xffffffffffffffff;             // 8 bytes, values 0 to 18446744073709551615

```

### Preprocessor

```c
                            // Comment to end of line
                            /* Multi-line comment */
#include  <stdio.h>         // Insert standard header file
#include "myfile.h"         // Insert file in current directory
#define X some text         // Replace X with some text
#define F(a,b) a+b          // Replace F(1,2) with 1+2
#define X \
 some text                  // Multiline definition
#undef X                    // Remove definition
#if defined(X)              // Conditional compilation (#ifdef X)
#else                       // Optional (#ifndef X or #if !defined(X))
#endif                      // Required after #if, #ifdef
```

### Literals

```c
255, 0377, 0xff             // Integers (decimal, octal, hex)
2147483647L, 0x7fffffffl    // Long (32-bit) integers
123.0, 1.23e2               // double (real) numbers
'a', '\141', '\x61'         // Character (literal, octal, hex)
'\n', '\\', '\'', '\"'      // Newline, backslash, single quote, double quote
"string\n"                  // Array of characters ending with newline and \0
"hello" "world"             // Concatenated strings
true, false                 // bool constants 1 and 0
NULL                        // Pointer type with the address of 0
```

### Declarations

```c
int x;                              // Declare x to be an integer (value undefined)
int x=255;                          // Declare and initialize x to 255
short s; long l;                    // Usually 16 or 32 bit integer (int may be either)
char c='a';                         // Usually 8 bit character
unsigned char u=255;
signed char s=-1;                   // char might be either
unsigned long x = 0xffffffffL;      // short, int, long are signed
float f; double d;                  // Single or double precision real (never unsigned)
bool b=true;                        // true or false, may also use int (1 or 0)
int a, b, c;                        // Multiple declarations
int a[10];                          // Array of 10 ints (a[0] through a[9])
int a[]={0,1,2};                    // Initialized array (or a[3]={0,1,2}; )
int a[2][2]={{1,2},{4,5}};          // Array of array of ints
char s[]="hello";                   // String (6 elements including '\0')
int* p;                             // p is a pointer to (address of) int
char* s="hello";                    // s points to unnamed array containing "hello"
void* p=NULL;                       // Address of untyped memory (NULL is 0)
enum weekend {SAT,SUN};             // weekend is a type with values SAT and SUN
enum weekend day;                   // day is a variable of type weekend
enum weekend{SAT=0,SUN=1};          // Explicit representation as int
enum {SAT,SUN} day;                 // Anonymous enum
const int c=3;                      // Constants must be initialized, cannot assign to
const int* p=a;                     // Contents of p (elements of a) are constant
int* const p=a;                     // p (but not contents) are constant
const int* const p=a;               // Both p and its contents are constant
int8_t,uint8_t,int16_t,
uint16_t,int32_t,uint32_t,
int64_t,uint64_t                    // Fixed length standard types
```

### STORAGE Classes

```c
int x;                      // Auto (memory exists only while in scope)
static int x;               // Global lifetime even if local scope
extern int x;               // Information only, declared elsewhere
```

### Statements

```c
x=y;                        // Every expression is a statement
int x;                      // Declarations are statements
;                           // Empty statement

{                           // A block is a single statement
    int x;                  // Scope of x is from declaration to end of block
}

if (x) a;                   // If x is true (not 0), evaluate a
else if (y) b;              // If not x and y (optional, may be repeated)
else c;                     // If not x and not y (optional)

while (x) a;                // Repeat 0 or more times while x is true

for (x; y; z) a;            // Equivalent to: x; while(y) {a; z;}

for (x : y) a;              // Range-based for loop e.g.
                            // for (auto& x in someList) x.y();

do a; while (x);            // Equivalent to: a; while(x) a;

switch (x) {                // x must be int
    case X1: a;             // If x == X1 (must be a const), jump here
    case X2: b;             // Else if x == X2, jump here
    default: c;             // Else jump here (optional)
}

break;                      // Jump out of while, do, or for loop, or switch
continue;                   // Jump to bottom of while, do, or for loop
return x;                   // Return x from function to caller
```

### Functions

```c
int f(int x, int y);        // f is a function taking 2 ints and returning int
void f();                   // f is a procedure taking no arguments
void f(int a=0);            // f() is equivalent to f(0)
f();                        // Default return type is int
inline f();                 // Optimize for speed
```

### Expressions

```c
t.x                         // Member x of struct or class t
p-> x                       // Member x of struct or class pointed to by p
a[i]                        // i'th element of array a
f(x,y)                      // Call to function f with arguments x and y
x++                         // Add 1 to x, evaluates to original x (postfix)
x--                         // Subtract 1 from x, evaluates to original x

sizeof x                    // Number of bytes used to represent object x
sizeof(T)                   // Number of bytes to represent type T
++x                         // Add 1 to x, evaluates to new value (prefix)
--x                         // Subtract 1 from x, evaluates to new value
~x                          // Bitwise complement of x
!x                          // true if x is 0, else false (1 or 0 in C)
-x                          // Unary minus
+x                          // Unary plus (default)
&x                          // Address of x
*p                          // Contents of address p (*&x equals x)

x * y                       // Multiply
x / y                       // Divide (integers round toward 0)
x % y                       // Modulo (result has sign of x)

x + y                       // Add, or \&x[y]
x - y                       // Subtract, or number of elements from *x to *y
x << y                      // x shifted y bits to left (x * pow(2, y))
x >> y                      // x shifted y bits to right (x / pow(2, y))

x < y                       // Less than
x <= y                      // Less than or equal to
x > y                       // Greater than
x >= y                      // Greater than or equal to

x & y                       // Bitwise and (3 & 6 is 2)
x ^ y                       // Bitwise exclusive or (3 ^ 6 is 5)
x | y                       // Bitwise or (3 | 6 is 7)
x && y                      // x and then y (evaluates y only if x (not 0))
x || y                      // x or else y (evaluates y only if x is false (0))
x = y                       // Assign y to x, returns new value of x
x += y                      // x = x + y, also -= *= /= <<= >>= &= |= ^=
x ? y : z                   // y if x is true (nonzero), else z
x , y                       // evaluates x and y, returns y (seldom used)
```

---

## References

- [Fixed width integer types (since C99)](https://en.cppreference.com/w/c/types/integer)
- [C Programming Tutorial for Beginners](https://www.youtube.com/watch?v=KJgsSFOSQv0)
- [In 54 Minutes, Understand the whole C and C++ compilation process](https://www.youtube.com/watch?v=ksJ9bdSX5Yo)
- [How to manage memory with malloc, calloc, realloc, and free in C](https://www.youtube.com/watch?v=lQP4X3odvHE)
- [How to use dynamically allocated arrays](https://www.youtube.com/watch?v=6Ir4l0VuI7Y)
- [C Programming Tutorials](https://www.youtube.com/playlist?list=PLA1FTfKBAEX4hblYoH6mnq0zsie2w6Wif)
- [The GNU C Library](https://www.gnu.org/software/libc/manual/html_node/index.html)
- [glibc Function and Macro Index](https://www.gnu.org/software/libc/manual/html_node/Function-Index.html)