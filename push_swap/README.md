# push_swap

`push_swap` is a sorting algorithm visualizer and optimizer. The goal is to sort a stack of integers using a limited set of operations, with the smallest possible number of moves. The project is split into two parts: the main program (`push_swap`) that outputs the optimal sequence of operations, and a bonus program (`checker`) that validates a sequence of operations.

I enjoyed this project quite a lot, probably one of my favorites in the common core.
A lot of algorithm (though not that complicated) and quite challenging. I tried finding alternative algorithms to solve this one, and even tried thinking of one by myself but in the end why try and recreate the wheel when it already exists. So I ended up doing like all my pairs and used the Turk Algorithm. I followed this guide on Medium : https://medium.com/@ayogun/push-swap-c1f5d2d41e97 so i guess it was created by the person who posted it ? Shoutout to A. Yigit Ogun if that's the case.

What I also liked about this project is that you can easily structure it and do it step by step : doing all the checkings, creating all the lists functions, creating your lists, implementing the operations and then doing the main part which is the sorting algorithm. Really fun

---

## Prototype

Mandatory:

```c
int main(int argc, char **argv); // push_swap
```

Takes a sequence of integers.
Either one argument surrounded by double quotes, for example : "1 5 2 4 0", or just many arguments, for example : 1 5 2 4 0.

Bonus:

```c
int main(int argc, char **argv); // checker
```

Takes the same type of sequence and reads from standard input for operations.
Checks if the operations can correctly sort the sequence.

---

## Behavior

- The program receives a list of integers as arguments and sorts them using only allowed stack operations:
  - `sa` : swap the first two elements of the A stack
  - `sb` : same for B
  - `ss` : `sa` and `sb` at the same time

  - `pa` : push the first element of B in top of A
  - `pb` : same from A to B

  - `ra` : shift up all elements of A by 1
  - `rb` : same for B
  - `rr` : `ra` and `rb` at the same time

  - `rra` : shift down all elements of A by 1
  - `rrb` : same for B
  - `rrr` : `rra` and `rrb` at the same time

- The `push_swap` executable prints the sequence of operations to standard output.
- The `checker` bonus executable reads a sequence of operations from standard input and checks if the stack is sorted at the end.

- The project must handle:
  - Invalid input (non-integers, duplicates, overflows)
  - Memory management (no leaks)
  - Large and small input sizes efficiently

Minimal usage example:

```bash
$ SEQ=\"1 5 2 4 0\"
$ ./push_swap \$SEQ
rra
pb
pb
ra
pa
pa
$ ./push_swap $SEQ | ./checker $SEQ
OK
```

---

## Files

Mandatory:

- `srcs/push_swap.c` — Main logic for sorting and outputting operations
- `srcs/operations1.c`, `srcs/operations2.c` — Implementation of stack operations
- `srcs/sorting.c`, `srcs/sorting2.c` — Sorting algorithms for different input sizes
- `srcs/init.c` — Stack initialization and input parsing
- `srcs/checkings.c` — Input validation and error handling
- `includes/push_swap.h` — Main header file
- `libft/` — Custom utility library (required for compilation)

Bonus:

- `bonus/srcs/checker.c` — Main logic for the checker
- `bonus/srcs/operations1_bonus.c`, `bonus/srcs/operations2_bonus.c` — Stack operations for checker
- `bonus/includes/checker.h` — Header for the bonus part

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds push_swap
make bonus  # builds push_swap and checker
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

---

## Notes

- The stack is implemented as a singly linked list.
- All operations are implemented according to the 42 subject requirements.
- This algorithm optimizes the **number of operations**, not the time of execution.
