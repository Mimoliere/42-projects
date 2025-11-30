# Libft

## 📋 Table of contents

- [About](#about)
- [Installation](#installation)
- [Usage](#usage)
- [Implemented functions](#implemented-functions)
  - [Libc functions](#libc-functions)
  - [Additional functions](#additional-functions)
  - [Bonus functions (linked lists)](#bonus-functions-linked-lists)
  - [Printf](#printf)
  - [Get Next Line](#get-next-line)
- [Project structure](#project-structure)
- [Compilation](#compilation)

## About

Libft is a custom C library implementing functions from the standard libc as well as extra utility functions.
This library is meant to be a personal toolbox for future C projects in the cursus and should be expanded as we progress.

It was a fairly quick and easy project to complete, a good way to get back into C at the beginning of the curriculum.

## Installation

```bash
git clone [your-repo]
cd libft
make
```

## Usage

1. Build the library with `make`
2. Include the header file in your C files:
```c
#include "includes/libft.h"
```
3. Compile your project with the library:
```bash
gcc -Wall -Wextra -Werror -o my_program my_file.c -L path_to_libft -lft
```

## Implemented functions

### Libc functions

#### Character checks
- `ft_isalpha` - Checks if the character is alphabetical
- `ft_isdigit` - Checks if the character is a digit
- `ft_isalnum` - Checks if the character is alphanumeric
- `ft_isascii` - Checks if the character is ASCII
- `ft_isprint` - Checks if the character is printable

#### String manipulation
- `ft_strlen` - Returns the length of a string
- `ft_strchr` - Searches for a character in a string
- `custom_strchr` - Custom version of strchr
- `ft_strrchr` - Searches for a character in a string (from the end)
- `ft_strncmp` - Compares two strings up to n characters
- `ft_strlcpy` - Copies a string with size limitation
- `ft_strlcat` - Concatenates strings with size limitation
- `ft_strnstr` - Searches for a substring in a string

#### Memory manipulation
- `ft_memset` - Fills a memory area with a byte
- `ft_bzero` - Sets a memory area to zero
- `ft_memcpy` - Copies a memory area
- `ft_memmove` - Copies a memory area (handles overlap)
- `ft_memchr` - Searches for a byte in memory
- `ft_memcmp` - Compares two memory areas

#### Conversion
- `ft_atoi` - Converts a string to an integer
- `ft_toupper` - Converts to uppercase
- `ft_tolower` - Converts to lowercase

#### Allocation
- `ft_calloc` - Allocates and initializes memory
- `custom_calloc` - Custom version of calloc with initialization value
- `ft_strdup` - Duplicates a string

### Additional functions

#### Advanced string manipulation
- `ft_substr` - Extracts a substring
- `ft_strjoin` - Joins two strings
- `altered_ft_strjoin` - Modified version of strjoin (frees s1)
- `ft_strtrim` - Trims unwanted characters from both ends
- `ft_split` - Splits a string using a delimiter
- `ft_cpytillsep` - Copies a string up to a separator
- `ft_strmapi` - Applies a function to each character (returns a new string)
- `ft_striteri` - Iterates over a string with a function (in-place)

#### Conversion and utilities
- `ft_itoa` - Converts an integer to a string

#### Output functions
- `ft_putchar_fd` - Writes a character to a file descriptor
- `ft_putstr_fd` - Writes a string to a file descriptor
- `ft_putendl_fd` - Writes a string followed by a newline
- `ft_putnbr_fd` - Writes a number to a file descriptor
- `ft_putnbrbase_fd` - Writes a number in a given base

#### Printf helpers (character counting)
- `ft_putchar_counts` - Writes a character and counts it
- `ft_putstr_counts` - Writes a string and counts characters
- `ft_putnbr_counts` - Writes a number and counts characters
- `ft_putnbrbase_counts` - Writes a number in a base and counts characters

### Bonus functions (linked lists)

- `ft_lstnew` - Creates a new node
- `ft_lstadd_front` - Adds a node at the beginning
- `ft_lstadd_back` - Adds a node at the end
- `ft_lstsize` - Counts the nodes
- `ft_lstlast` - Returns the last node
- `ft_lstdelone` - Deletes a node
- `ft_lstclear` - Deletes and frees all nodes
- `ft_lstiter` - Iterates over the list
- `ft_lstmap` - Applies a function and creates a new list

### Printf

A custom implementation of `printf` (Detailed in the corresponding directory)

### Get Next Line

- `get_next_line` - Reads a line from a file descriptor (Detailed in the corresponding directory)

### Additional utility functions

- `ft_strcmp` - Compares two full strings
- `ft_has_char` - Checks if a string contains a given character
- `ft_strndup` - Duplicates n characters from a string
- `free_arr` - Frees an array of strings
- `ft_countwords` - Counts words in a string
- `ft_max` - Returns the maximum of two integers
- `ft_min` - Returns the minimum of two integers
- `ft_atoll` - Converts a string to a long long
- `is_allchar` - Checks if all characters in a string are equal to a given character
- Extended check functions (`ft_isalldigit`, `ft_isallalpha`, `ft_isallalnum`, etc.)

## Project structure

```text
libft/
├── Makefile                # Build file
├── README.md               # This file
├── includes/
│   └── libft.h             # Main header file
└── srcs/                   # Source files
    ├── ft_*.c              # Core functions
    ├── *_bonus.c           # Bonus functions
    ├── ft_printf*.c        # Printf implementation
    └── get_next_line.c     # GNL implementation
```

## Compilation

### Available make targets

- `make` or `make all` - Builds the base library
- `make bonus` - Builds the library with bonus functions
- `make clean` - Removes object files
- `make fclean` - Removes object files and the library
- `make re` - Full rebuild

### Compilation flags

The library is compiled with the following flags:
- `-Wall` - Enable common warnings
- `-Wextra` - Enable extra warnings  
- `-Werror` - Treat warnings as errors
- `-g3` - Enable debug information
