# so_long



`so_long` is a simple 2D game where the player must collect all collectibles and reach the exit, navigating through a map filled with obstacles. The project is an introduction to graphical programming using the MiniLibX library, 42's graphical library.

I like this project SO MUCH !
It's obviously one of my favorites because it's easy and funny to make. Plus, I had friends who helped me to do the assets so I felt like we were a tiny team developing our silly game.
Anyway, it was interesting to see how to use assets and how to implement the basic mechanics of a 2D game.

## **THIS IS NOT THE FINAL VERSION OF MY PROJECT**
**The final version is physically at school. Since I validated this project, I don't have access to it's dedicated git repository created by 42's system. I will need to personnally go to school and get the final version of my files to put it here.**

---

## IMPORTANT

- If you want to clone this repository with the MiniLibX library included, use:

```bash
git clone --recurse-submodules git@github.com:42paris/minilibx-linux.git
```

- If you already cloned without submodules, run:

```bash
git submodule update --init --recursive
```

This will automatically fetch the MiniLibX sources into `includes/mlx`.

---

## Prototype

Mandatory:

```c
int main(int argc, char **argv); // so_long
```

- Takes a single argument: the path to a `.ber` map file.

---

## Behavior

- The program loads a map from a `.ber` file and displays it in a window.
- The player (P) moves using the arrow keys or WASD.
- The goal is to collect all collectibles (C) and reach the exit (E).
- The map must be surrounded by walls (1), and only valid characters are allowed: 0 (empty), 1 (wall), C (collectible), E (exit), P (player).
- The game closes when the player wins or presses ESC.
- The program must handle:
  - Invalid maps (missing elements, not rectangular, not surrounded by walls, unreachable exit/collectibles)
  - Invalid input (wrong file extension, non-existing file)
  - Memory management (no leaks)

Minimal usage example:

```bash
$ ./so_long maps/map.ber
```

---

## Files

Mandatory:

- `srcs/so_long.c` — Main logic and window management
- `srcs/checks.c` — Map validation and parsing
- `srcs/images.c` — Image loading and rendering
- `srcs/map.c` — Map utilities and helpers
- `srcs/move.c` — Player movement and game logic
- `srcs/errors.c` — Error handling and resource cleanup
- `includes/so_long.h` — Main header file
- `includes/libft/` — Custom utility library (required for compilation)
- `includes/mlx/` — MiniLibX graphics library (as a git submodule)
- `assets/` — Game sprites (XPM images)
- `maps/` — Example map files

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds so_long
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

---

## Notes

- I parsed the map using my own floodfill algorithm
- All error cases are handled gracefully with clear messages.
- Sprites are loaded from the `assets/` folder (thanks to Capucine and Alexis for the sprites).
