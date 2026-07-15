*This project has been created as part of the 42 curriculum by dieandra.*

# ft_printf

## Description

**ft_printf** is a foundational project in the 42 curriculum. The goal of this project is to recreate the behavior of the standard C library's `printf` function, using variadic functions in C.

Through this project, I gained a deep understanding of variadic arguments (`va_list`, `va_start`, `va_arg`, and `va_end`), formatted output, and low-level C memory handling, all while adhering strictly to the 42 Norm constraints.

The project produces a static library called `libftprintf.a` that handles several formatting specifiers and can be linked to other C projects.

---

## Features

This implementation supports the following mandatory conversions:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string of characters (handles `NULL` safely as `(null)`). |
| `%p` | Prints a `void *` pointer argument in hexadecimal format (prefixed by `0x`, handles `NULL` safely as `(nil)`). |
| `%d` | Prints a decimal (base 10) number. |
| `%i` | Prints an integer in base 10. |
| `%u` | Prints an unsigned decimal (base 10) number. |
| `%x` | Prints a number in hexadecimal (base 16), lowercase. |
| `%X` | Prints a number in hexadecimal (base 16), uppercase. |
| `%%` | Prints a literal percent sign. |

---

## Instructions

### Prerequisites

- A Linux environment (e.g. Ubuntu 24.04)
- A C compiler (`gcc` or `clang`)
- GNU Make

### Compilation

To compile the library, run:

```bash
make
```

This compiles the source files and bundles them into the `libftprintf.a` static library at the root of the repository.

### Cleaning Utilities

Remove object files (`.o`):

```bash
make clean
```

Remove object files and the compiled library (`libftprintf.a`):

```bash
make fclean
```

Rebuild the entire library from scratch:

```bash
make re
```

### Usage Example

To use `ft_printf` in your own C project, include the header file and link the static library during compilation.

1. Include the header in your C file:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! The answer is %d.\n", "Diego", 42);
    return (0);
}
```

2. Compile your program alongside the library:

```bash
gcc main.c -L. -lftprintf -o my_program
```

---

## Algorithm and Data Structure Justification

### Algorithm Selection

The parser follows a **single-pass sequential scanning algorithm** over the format string. It iterates through the string character by character:

1. Characters that are not `%` are written directly to standard output using `write()`, incrementing the total character counter.
2. When a `%` symbol is found, the algorithm checks the character that follows it (the specifier) to determine which formatting function to call, via a helper router function (`ft_check_and_count`).
3. Variadic arguments are retrieved sequentially from the `va_list` structure, according to the type required by each specifier.

### Structural Choices

Rather than relying on complex data structures or dynamic memory allocation (which would add the risk of memory leaks and unnecessary overhead), the implementation relies on **recursion and call stack management** for numeric base conversions (e.g. `%x`, `%X`, `%u`, `%d`, `%i`).

This approach was chosen because:

- **Memory safety:** it minimizes heap allocations (`malloc`), reducing the risk of memory leaks and improving reliability.
- **Modularity:** formatting logic is split into small, specialized files (e.g. `ft_puthex.c`, `ft_putptr.c`, `ft_putunbr.c`), following good software engineering practices.
- **Efficiency:** characters are processed and printed on the fly, keeping the memory footprint small.

---

## Resources

### Documentation

- Linux manual pages: `man 3 printf`, `man 3 stdarg`
- *The C Programming Language* — Brian W. Kernighan & Dennis M. Ritchie
- POSIX and ISO C99 standards for formatted output

### References

- [GCC Variadic Functions Guide](https://gcc.gnu.org/onlinedocs/gcc/Type-Generic-Functions.html)
- [Standard C Library Reference — printf](https://cplusplus.com/reference/cstdio/printf/)

### AI Usage

AI (LLM) tools were used during the development of this project to assist with the following specific tasks:

1. **Edge case research** — checking how the standard `printf` behaves on different platforms (especially Ubuntu) for edge cases such as `INT_MIN` in `%d`/`%i` and `NULL` handling in `%p` (`(nil)` vs `(null)`).
2. **Code review and Norm compliance** — used to check for dead code and structural issues in line with the 42 Norm.
3. **Documentation drafting** — used to help organize and structure this `README.md`.

*Note: all core function implementations, logic flows, algorithm design, and the build system (Makefile) were written and validated by the author.*

---

## Author

- **Diego Andrade**
- **42 login:** `dieandra`
- **GitHub:** [diandrade](https://github.com/diandrade)
