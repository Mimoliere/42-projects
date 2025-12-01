# get_next_line

`get_next_line` is a function that reads a file descriptor line by line.  
It allows you to retrieve one line at a time from a file, standard input, or any valid file descriptor, while keeping the reading state between calls.

The goal of this project is to implement a robust line reader that correctly handles:
- Arbitrary line length
- Internal buffering
- Multiple file descriptors (in the bonus part)

---

## Prototype

Mandatory part:

```c
char	*get_next_line(int fd);
```

- `fd`: file descriptor to read from
- Returns:
  - A heap-allocated string containing the next line (including the newline `\n` if present)
  - `NULL` if there is nothing more to read or in case of error

---

## Behavior

- Each call to `get_next_line(fd)` returns the **next line** from `fd`.
- Internally, the function uses a buffer of size `BUFFER_SIZE` (defined at compile time).
- The function:
  - Keeps leftover data between calls
  - Stops reading at each newline character `\n`
  - Returns `NULL` at EOF and on error

Minimal usage example in srcs/main.c (Only for the mandatory part, not for the bonus)

---

## Files

Mandatory:

- `srcs/get_next_line.c`
  Main logic of the `get_next_line` function.

- `srcs/get_next_line_utils.c`
  Utility functions used by `get_next_line` (string handling, memory, etc.).

Bonus:

- `srcs/get_next_line_bonus.c`
  Extended version supporting **multiple file descriptors** simultaneously.

- `srcs/get_next_line_utils_bonus.c`
  Utility functions for the bonus version. Exactly the same as for the mandatory part.

Header:

- `includes/get_next_line.h` / `includes/get_next_line_bonus.h`
  Contains the prototypes and required includes.

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds the mandatory program
make bonus  # builds the bonus part
make clean  # removes object files
make fclean # removes object files and the program
make re     # full rebuild
```

---

## Notes

- The function must handle:
  - Files with or without a trailing newline
  - Large files
  - Small and large `BUFFER_SIZE`
- In the bonus part, calls like:

```c
line1 = get_next_line(fd1);
line2 = get_next_line(fd2);
```

must work independently for each file descriptor.
