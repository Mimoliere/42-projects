# minishell

`minishell` is a simple Unix shell implementation that replicates the core functionalities of bash. The project focuses on processes, file descriptors, signal handling, and command parsing. It provides an interactive command-line interface with support for pipes, redirections, environment variables, and built-in commands.

It was SUCH A CHALLENGE. It's undoubtably the hardest project I had to do, mainly because I got a lot of complications threw it.
It's a pair project. I had a mate to do it at first, we barely started the project together but we weren't working on the same pace nor with the same organization and mindset, so we separated.
Therefore I did 95% of this project alone from scratch and with barely some help (I did it in the summer vacation period so everyone was out relaxing and having fun).
At the end I had a friend that struggled with her mate too so she came and did the signals part and a lot of testing too (thank you Imene you're awesome).

It was really a challenging and it took me like 2 months but it's clearly one of my favorite projects, not because I learned a lot but because it requires a lot of discipline and it's a project that needs a good structure. If I learned something it would definitely be the organisation.
As you can see the project is pretty massive compared to all the other ones that came before, and doing it alone really required a lot of focus to not become lost and burn out.

Anyway enoug yapping. This project is fun and hard, that's all you need to know.

---

## Prototype

```c
int main(int argc, char **argv, char **envp); // minishell
```

- Takes no arguments and runs in interactive mode.
- Uses the `readline` library for command input and history management.
- Displays a custom prompt: `minishishishi 👒😁 `

---

## Behavior

- The shell displays a prompt and waits for user input.
- Supports command execution with:
  - **Pipes** (`|`) — Connect multiple commands
  - **Redirections** (`<`, `>`, `>>`, `<<`) — Input/output redirection and heredocs
  - **Environment variables** — Expansion with `$VAR` syntax
  - **Exit status** — Access last command status with `$?`
  - **Quotes** — Single quotes (`'`) prevent expansion, double quotes (`"`) allow expansion
  - **Signals** — Handles `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` like bash

- Built-in commands:
  - `echo` — Print arguments (with `-n` option support)
  - `cd` — Change directory
  - `pwd` — Print working directory
  - `export` — Set environment variables
  - `unset` — Remove environment variables
  - `env` — Display environment variables
  - `exit` — Exit the shell
  - `history` — Display command history

- Error handling:
  - Syntax errors (unclosed quotes, invalid pipes, etc.)
  - Command not found
  - Permission denied
  - Memory allocation failures

Minimal usage example:

```bash
$ ./minishell
minishishishi 👒😁 echo "Hello World"
Hello World
minishishishi 👒😁 ls -la | grep minishell | wc -l
1
minishishishi 👒😁 export VAR=42
minishishishi 👒😁 echo $VAR
42
minishishishi 👒😁 exit
```

---

## Files

Mandatory:

- `src/main.c` — Entry point and main loop
- `src/process.c` — Command processing and execution flow
- `src/lexer/lexing.c` — Tokenization of user input
- `src/parser/parsing.c` — Build abstract syntax tree from tokens
- `src/parser/paths.c` — PATH resolution for command execution
- `src/expander/expanding.c` — Variable expansion logic
- `src/expander/expanding_utils.c` — Expansion utilities
- `src/executor/exec.c` — Command execution logic
- `src/executor/pipe.c` — Pipe management
- `src/executor/redir.c` — Redirection handling
- `src/executor/heredoc.c` — Heredoc implementation
- `src/executor/cmds.c` — Command utilities
- `src/executor/execution.c` — Execution helpers
- `src/builtins/builtins1.c` — Built-in commands (`echo`, `cd`, `pwd`, `env`)
- `src/builtins/builtins2.c` — Built-in commands (`unset`, `export`, `exit`)
- `src/builtins/built_tools.c` — Built-in utilities
- `src/builtins/export.c` — Export command implementation
- `src/environment/env1.c` — Environment variable management
- `src/environment/env2.c` — Environment utilities
- `src/environment/env3.c` — Environment conversion helpers
- `src/signals/signals.c` — Signal handling setup
- `src/signals/signals2.c` — Interactive mode signals
- `src/signals/signals3.c` — Execution mode signals
- `src/errors/errors1.c` — Error handling
- `src/errors/errors2.c` — Error utilities
- `src/utils/` — Various utility functions (split, strdup, strjoin, free functions)
- `src/utils/lists/` — Linked list operations (line tokens, history)
- `src/utils/trees/` — Binary tree operations (AST management)
- `include/minishell.h` — Main header file
- `include/structs.h` — Data structure definitions
- `include/luffy.h` — ASCII art banner
- `include/libft/` — Custom utility library (required for compilation)

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds minishell
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

### Dependencies

The project requires:
- `readline` library (`-lreadline`)
- `history` library (`-lhistory`)

Install on Ubuntu/Debian:
```bash
sudo apt-get install libreadline-dev
```

---

## Notes

- The shell uses a lexer-parser-executor architecture:
  1. **Lexer** — Tokenizes input into a linked list
  2. **Parser** — Builds an abstract syntax tree (AST)
  3. **Expander** — Handles variable expansion
  4. **Executor** — Executes commands with proper redirection and piping

- Signal handling is context-aware:
  - Interactive mode: `Ctrl+C` displays a new prompt
  - Execution mode: `Ctrl+C` terminates the current command
  - Heredoc mode: `Ctrl+C` aborts heredoc input

- Memory management is handled carefully with custom free functions for all data structures.

- The shell prevents piping to/from stdin/stdout when not running interactively.

- Command history is maintained throughout the session and can be accessed with arrow keys (readline feature) or the `history` built-in.

- I used a binary tree to parse the command lines. It definitely isn't required, but since I learned that notion just recently at that time I really wanted to apply it to a real project and situation.
