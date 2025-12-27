# pipex

`pipex` is a project that replicates the shell's pipe (`|`) behavior, allowing you to execute two commands with input/output redirection between them. The goal is to understand process creation, file descriptors, and inter-process communication in Unix.

This project was interesting but pretty annoying to understand and execute because of all the memory and file management, it was a pain to track all the children and understand where were the bugs etc.

TECHNICALLY I have done the bonuses for this project (multiple pipes + supporting '<<' and '>>' + the here_doc system).
I did code these functionnalities in the [minishell](../minishell/) project and managed them pretty well but I didn't take the time to implement them in my pipex project. Maybe someday I'll do it if I'm not lazy.

Honestly it's probably one of the few projects that I'm not really proud of because of the coding style and a lot of memory and file mistakes due to my weak understanding of the pipe concept at that time.

---

## Prototype

Mandatory:

```c
int main(int argc, char **argv, char **envp); // pipex
```

- Takes exactly 4 arguments: `infile cmd1 cmd2 outfile`
- Example: `./pipex infile "ls -l" "wc -l" outfile`

---

## Behavior

- The program executes the equivalent of:
  ```sh
  < infile cmd1 | cmd2 > outfile
  ```
- It:
  - Opens `infile` for reading and `outfile` for writing (truncating or creating it)
  - Executes `cmd1` with its input from `infile` and output piped to `cmd2`
  - Executes `cmd2` with its input from the pipe and output to `outfile`
  - Handles all errors (file, command, permission, etc.) gracefully
  - Cleans up all resources and file descriptors

Minimal usage example:

```bash
$ echo -e "hello\nworld" > infile
$ ./pipex infile "cat" "wc -l" outfile
$ cat outfile
2
```

---

## Files

- `srcs/pipex.c` — Main logic and process management
- `srcs/pipex_utils.c`, `srcs/pipex_utils_2.c` — Utility functions (parsing, error handling, memory management)
- `includes/pipex.h` — Main header file
- `libft/` — Custom utility library (required for compilation)

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds pipex
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

---

## Notes

- The project is a great introduction to Unix process management and inter-process communication.
