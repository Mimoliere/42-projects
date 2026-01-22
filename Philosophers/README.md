# Philosophers

`Philosophers` is a classic concurrency problem simulation. The goal is to manage a set of philosophers who alternate between thinking, eating, and sleeping, while sharing forks (mutexes) and avoiding deadlocks and starvation. This project is a great introduction to multithreading, synchronization, and resource sharing in C.

---

## Prototype

Mandatory:

```c
int main(int argc, char **argv);
```

- Takes 4 or 5 arguments:
  - number_of_philosophers
  - time_to_die (ms)
  - time_to_eat (ms)
  - time_to_sleep (ms)
  - [number_of_times_each_philosopher_must_eat] (optional)

---

## Behavior

- Each philosopher is a thread that cycles through thinking, eating, and sleeping.
- Philosophers must pick up two forks (mutexes) to eat.
- The simulation ends when a philosopher dies (does not eat in time) or when all have eaten the required number of times (if specified).
- The program must handle:
  - Argument validation
  - Mutex initialization and destruction
  - Thread creation and joining
  - Deadlock and starvation avoidance
  - Clean resource management (no leaks)

Minimal usage example:

```bash
$ ./philo 5 800 200 200
$ ./philo 5 800 200 200 7
```

---

## Files

- `srcs/philo.c` — Main logic, initialization, and thread management
- `srcs/actions.c` — Philosopher actions (thinking, eating, sleeping)
- `srcs/checks.c` — Argument and state validation
- `srcs/errors.c` — Error handling
- `srcs/manage.c` — Time management and state checks
- `srcs/monitoring.c` — Monitoring thread and death detection
- `srcs/tools.c` — Utility functions and cleanup
- `includes/philo.h` — Main header file

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds philo
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

---

## Notes

- The project uses POSIX threads (pthreads) and mutexes for synchronization.
- All error cases are handled with clear messages and proper resource cleanup.
- The code is modular and split by responsibility (main logic, actions, monitoring, utils, etc.).
- The project is a great exercise in concurrent programming and synchronization in C.
