# 42-projects

This repository groups the projects I am doing as part of my curriculum at 42 school.

This GitHub will be updated progressively as I move forward in the cursus. It will be improved as I acquire new knowledge.

The projects here are in no way meant to be perfect. They are the projects of a student who is constantly progressing day by day, so the oldest ones will probably have less consistency and polish than the more recent ones (unless I take the time to give them a bit of a refresh).
I am proud of the progress I have made since the beginning, and I fully intend to keep evolving and learning. I hope this repository can reflect that.

PS: I used AI to help me write the READMEs.

---

## Summary

- [Repository organization](#repository-organization)
- [Prerequisites & tools](#prerequisites--tools)
- [Build and test (generic)](#build-and-test-generic)
- [Project list](#project-list)
- [Add a new project](#add-a-new-project)
- [Personal notes](#personal-notes)

---

## Repository organization

Typical expected tree for each project (example for `libft/`):

```text
42-projects/
├─ libft/
│  ├─ README.md
│  ├─ Makefile
│  ├─ includes/         # header files .h
│  ├─ srcs/             # source files .c/.cpp
│  ├─ subject/          # project statement and resources
│  ├─ tests/            # tests and/or validation scripts (optional)
│  └─ assets/           # maps, example files… (optional)
├─ get_next_line/
├─ ft_printf/
└─ ...
```

Explanations:
- A local `README.md` per project for specific instructions.
- A `Makefile` per project with the usual targets (`all`, `clean`, `fclean`, `re`, `bonus` if needed).
- Respect of the 42 Norm (Norminette) for C projects.

---

## Prerequisites & tools

- Build tools:
  - `make`
  - `gcc`/`clang` for C, `c++` for C++ modules (often with `-std=c++98`)

---

## Build and test (generic)

For a typical C/C++ project:

```bash
# From the project folder (e.g.: libft/)
make            # builds the default target
make bonus      # if the project has bonus parts
make clean      # removes object files
make fclean     # removes binaries + objects
make re         # rebuilds from scratch
norminette      # checks the norm
```

Running tests (if available):

```bash
cd tests
./run_tests.sh  # (example) or commands described in the project README
```

---

## Project list

| Project             | Folder                | Short description                                    | Status    | Mark | Subject |
|---------------------|-----------------------|------------------------------------------------------|-----------|------|---------|
| Libft               | [libft](./libft/)     | Personal C library                                   | Finished  | 106  | [subject_libft](./libft/subject/libft.en.subject.pdf)     |
| get_next_line       | [get_next_line](./get_next_line/) | Line-by-line file/FD reading            | Finished  | 100    | [subject_ft_printf](./ft_printf/subject/en.subject.pdf)     |
| ft_printf           | [ft_printf](./ft_printf/) | `printf` reimplementation                       | Finished  | —    | —     |
| Born2beroot         | [born2beroot](./born2beroot/) | System administration and virtualization       | Finished  | —    | —     |
| push_swap           | [push_swap](./push_swap/) | Sorting using stack operations                  | Finished  | —    | —     |
| so_long             | [so_long](./so_long/) | Small 2D game (MiniLibX)                           | Finished  | —    | —     |
| pipex               | [pipex](./pipex/) | Pipe management                                     | Finished  | —    | —     |
| minishell           | [minishell](./minishell/) | Mini shell / command interpreter               | Finished  | —    | —     |
| philosophers        | [philosophers](./philosophers/) | Threads, mutexes, concurrency                 | Finished  | —    | —     |
| NetPractice         | [netpractice](./netpractice/) | IP networking exercises                          | Finished  | —    | —     |
| cub3d               | [cub3d](./cub3d/)     | Raycasting (inspired by Wolfenstein 3D)             | In progress | —  | —     |
| CPP Modules         | [cpp_modules](./cpp_modules/) | C++ modules (OOP, orthodox canonical form)   | Upcoming  | —    | —     |
| Inception           | [inception](./inception/) | Docker, docker-compose                            | Upcoming  | —    | —     |
| ft_irc              | [ft_irc](./ft_irc/)   | IRC server                                          | Upcoming  | —    | —     |
| webserv             | [webserv](./webserv/) | HTTP server                                         | Upcoming  | —    | —     |
| ft_transcendence    | [ft_transcendence](./ft_transcendence/) | Full-stack web project                     | Upcoming  | —    | —     |

---

## Add a new project

1) Create the folder:
```bash
mkdir -p <project_name>/{src,include,tests,assets,subject}
cp -n .gitignore <project_name>/ 2>/dev/null || true
```

2) Add a minimal `README.md`:
```md
# <project_name>
Short description, dependencies, build and run instructions.
```

3) Create a simple `Makefile` (C example):
```make
NAME := <binary_or_lib>
CC   := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:.c=.o)
INCS := -I include

all: $(NAME)

$(NAME): $(OBJS)
    $(CC) $(CFLAGS) $(INCS) -o $@ $(OBJS)

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
```

4) Update the [Project list](#project-list) and the [Progression](#progression-checklist) above.

---

## Personal notes

- Document technical choices and pitfalls to make it easier to revisit later.
- Add tests and READMEs for older projects.
