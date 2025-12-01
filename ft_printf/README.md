# ft_printf

`ft_printf` is a partial reimplementation of the standard C library function `printf`.  
The goal is to handle formatted output to the standard output while accurately counting the number of printed characters.

This was quite an interesting project in my opinion.
When I started learning coding before 42, I never really questionned how all the functions I used were coded. Although we code a lot of C library functions in the Piscine (the entry test for 42), I was really curious about this one and I am pretty happy to know how the function I use all the time works now.

## Prototype

```c
int ft_printf(const char *str, ...);
```

- Returns: the number of printed characters  
- Returns `-1` in case of a write error

## Supported conversions

`ft_printf` supports the following conversions:

- `%c`: character
- `%s`: string
- `%d` / `%i`: signed decimal integer
- `%u`: unsigned decimal integer
- `%x`: unsigned hexadecimal integer (lowercase)
- `%X`: unsigned hexadecimal integer (uppercase)
- `%p`: pointer address (format `0x...`)
- `%%`: prints the `%` character

Minimal usage example in srcs/main.c

## Files

### Main files
- `srcs/ft_printf.c`  
  - Parses the format string, reads variadic arguments and delegates printing to helper functions.
- `srcs/ft_printf_functions.c`  
  - Contains internal functions that handle each conversion type.
- `includes/ft_printf.h`  
  - Declares the public `ft_printf` function and the helper counting functions.

### Helper functions

These functions write to standard output while incrementing a counter passed by address:

- `ft_putchar_counts(char c, int *charcount)`  
  Writes a character and increments `*charcount`.

- `ft_putstr_counts(char *s, int *charcount)`  
  Writes a string (or `(null)` if `s == NULL`) and increments `*charcount`.

- `ft_putnbr_counts(int n, int *charcount)`  
  Writes a signed integer in base 10 and increments `*charcount`.

- `ft_putnbrbase_counts(uintptr_t n, char *base, int *charcount, int iter)`  
  Writes a number in a given base (hexadecimal for `%x`, `%X`, `%p`) and increments `*charcount`.

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds the mandatory program
make clean  # removes object files
make fclean # removes object files and the program
make re     # full rebuild
```
