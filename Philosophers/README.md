# Philosophers

`Philosophers` is an implementation of the classic Dining Philosophers Problem, a synchronization and concurrency challenge. The project focuses on threading, mutexes, and race condition prevention. Each philosopher is represented by a thread that must eat, sleep, and think while sharing forks (resources) with neighbors, all while avoiding deadlocks and starvation.

This project ate my soul.
Jokes aside, it was interesting, but the thing that made me dislike this project is the difficulty to test it and to be sure that EVERYTHING was alright. No deadlocks, no special case, no delay, NOT ANY ERROR, you must handle EVERYTHING THAT IS POSSIBLE.
So my vision was pretty blurry when doing this project, I also had a small mistake that caused some delay, a friend managed to help me solve it (thanks).
Overall, I learned a lot, but definitely one of my least favorite projects.

---

## Prototype

```c
int main(int argc, char **argv);
```

Takes 4 or 5 arguments:
- `number_of_philosophers` — Number of philosophers (and forks)
- `time_to_die` — Time (in ms) before a philosopher dies without eating
- `time_to_eat` — Time (in ms) a philosopher spends eating
- `time_to_sleep` — Time (in ms) a philosopher spends sleeping
- `[number_of_times_each_philosopher_must_eat]` — Optional: simulation stops when all philosophers have eaten this many times

---

## Behavior

- Each philosopher is a thread that runs concurrently.
- Philosophers alternate between three states: **thinking**, **eating**, and **sleeping**.
- Each philosopher needs **two forks** to eat: their own fork and their neighbor's fork.
- A philosopher dies if they don't start eating within `time_to_die` milliseconds from their last meal.
- The simulation stops when:
  - A philosopher dies (prints death message)
  - All philosophers have eaten `number_of_times_each_philosopher_must_eat` times (optional, prints "Yee haw !")

### Rules:
- Philosophers must eat without dying of starvation.
- Forks must be shared between neighbors (no philosopher can hold two forks indefinitely).
- Messages are printed in the format: `timestamp_in_ms philosopher_number action`
- Actions: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`
- No data races allowed (all shared data is protected by mutexes).

### Implementation details:
- Uses a circular linked list to represent philosophers sitting at a round table.
- Each fork is a mutex, and each philosopher has one fork.
- A monitoring thread checks continuously if any philosopher has died.
- Turn-based system prevents deadlocks (philosophers take turns grabbing forks).
- Even-numbered philosophers wait slightly before starting to avoid initial rush.

---

## Usage Examples

```bash
$ ./philo {number_of_philosophers} {time_to_die} {time_to_eat} {time_to_sleep} {number_of_meals \(eventually\)}
```

### Test 1: Should NOT die (enough time to eat)
```bash
$ ./philo 5 800 200 200
```
**Expected:** Philosophers eat and sleep indefinitely, no one dies.

---

### Test 2: Should die (insufficient time)
```bash
$ ./philo 4 310 200 100
```
**Expected:** A philosopher dies after `time_to_die` ms without eating.

---

### Test 3: One philosopher (should die)
```bash
$ ./philo 1 800 200 200
```
**Expected:** With only one fork available, the philosopher cannot eat and dies.

---

### Test 4: Required number of meals
```bash
$ ./philo 5 800 200 200 7
```
**Expected:** Simulation stops when all philosophers have eaten 7 times (prints "Yee haw !").

---

### Test 5: Tight timing (edge case)
```bash
$ ./philo 4 410 200 200
```
**Expected:** All philosophers survive with careful synchronization.

---

### Test 6: Large number of philosophers
```bash
$ ./philo 200 800 200 200
```
**Expected:** Simulation runs smoothly without race conditions or crashes.

---

### Test 7: Quick death scenario
```bash
$ ./philo 4 200 210 100
```
**Expected:** Philosopher 2 cannot eat in time and dies at 200ms.

---

## Files

Mandatory:

- `srcs/philo.c` — Main logic: initialization, thread creation, and cleanup
- `srcs/actions.c` — Philosopher actions: thinking, eating, sleeping, fork handling
- `srcs/monitoring.c` — Death monitoring thread and monitor initialization
- `srcs/checks.c` — Argument validation, mutex checks, meal counting, turn management
- `srcs/manage.c` — Time management and death state checking
- `srcs/tools.c` — Utility functions: `ft_atoi`, `ft_strlen`, `print`, custom `usleep`, memory cleanup
- `srcs/errors.c` — Error handling and messages
- `includes/philo.h` — Header file with structures and function prototypes

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

- The program uses **pthread** library for threading and mutexes.
- Data structures:
  - `t_philo` — Represents a philosopher (thread, mutexes, state)
  - `t_monitor` — Global monitor tracking death, meals, and timing

- **Synchronization strategy:**
  - Each philosopher has their own fork (mutex).
  - Turn-based system ensures fair access to forks and prevents deadlock.
  - Even-numbered philosophers start with a small delay to reduce initial contention.
  - A dedicated monitoring thread continuously checks if any philosopher has exceeded `time_to_die` without eating.

- **Mutex protection:**
  - `dead` — Protects death status
  - `write` — Protects console output
  - `time` — Protects timestamp operations
  - `meals` — Protects meal counter
  - `turns` — Protects turn-based fork access
  - `wait` — Protects individual philosopher's last meal time
  - `fork` — Protects fork availability

- Custom `ft_usleep` function provides more accurate timing than standard `usleep`.

- Memory is properly cleaned up with `clear_philos` function that destroys all mutexes and frees allocated memory.

- The circular linked list structure naturally represents philosophers sitting at a round table, making neighbor access intuitive. I decided to use this structure because I could vizualize better and I wanted to apply it.
