# cub3D

`cub3D` is a 3D game engine inspired by the classic Wolfenstein 3D, the first-ever FPS (First Person Shooter). This project implements raycasting to render a 3D perspective from a 2D map. It's an introduction to graphics programming, involving texture mapping, player movement, and real-time rendering using the MiniLibX library.

It was SO MUCH FUN ! Clearly one of my favorites ! Thanks to Artis, my friend and mate for this project, I really had a good time coding this and it was really great to work with him.
I started by doing the algorithmic part while my friend did managed the map parsing and textures application. We then merged our two parts together to get a first prototype for better vizualisation and testing. Later, I had a lot of things going so he took the initiative to rework a lot of my part because some things were missing or poorly optimized.
The work was really smooth and the subject absolutely interesting so it's a project I truly appreciate.

---

## IMPORTANT

- If you want to clone this repository with the MiniLibX library included, use:

```bash
git clone --recurse-submodules <your-repo-url>
```

- If you already cloned without submodules, run:

```bash
git submodule add https://github.com/42Paris/minilibx-linux.git includes/mlx
git submodule update --init --recursive
```

This will automatically fetch the MiniLibX sources into `includes/mlx`.

---

## Prototype

```c
int main(int argc, char **argv); // cub3D
```

- Takes a single argument: the path to a `.cub` scene configuration file.

---

## Behavior

- The program loads a scene from a `.cub` file and renders a 3D view in a window.
- The player can move through the map using keyboard controls:
  - **W, A, S, D** — Move forward, left, backward, right
  - **Left/Right arrows** — Rotate camera view
  - **ESC** — Close the window and exit
- The scene is rendered using **raycasting**:
  - The map is represented as a 2D grid (walls and empty spaces).
  - Rays are cast from the player's position at different angles within the field of view (FOV).
  - Each ray checks for wall intersections using the DDA (Digital Differential Analysis) algorithm.
  - Wall heights are calculated based on ray distances (farther walls appear smaller).
  - Textures are applied to walls based on their direction (North, South, East, West).
- The program handles:
  - Invalid maps (not closed by walls, invalid characters, multiple players, no player)
  - Missing or invalid textures
  - Wrong color format (RGB values must be 0-255)
  - Invalid file extension (must be `.cub`)
  - Memory management (no leaks)

Minimal usage example:

```bash
$ ./cub3D maps/map.cub
```

---

### Map Format (.cub file)

A `.cub` file contains:
1. **Texture paths** for each wall direction:
   ```
   NO ./textures/north_wall.xpm
   SO ./textures/south_wall.xpm
   WE ./textures/west_wall.xpm
   EA ./textures/east_wall.xpm
   ```

2. **Floor and ceiling colors** in RGB format:
   ```
   F 52,162,3      (Floor: green)
   C 0,33,243      (Ceiling: blue)
   ```

3. **Map grid** using these characters:
   - `0` — Empty space (walkable)
   - `1` — Wall
   - `N, S, E, W` — Player starting position and orientation (North, South, East, West)
   - Space — Outside map boundaries (must be surrounded by walls)

Example map:
```
111111111111111111111
1000000000N1000000001
100000000001000000001
100000000010000000011
100000000001000000001
100000000001000000001
111111111111111111111
```

---

## Files

Mandatory:

- `srcs/cub3D.c` — Main entry point and window refresh loop
- `srcs/init.c` — Window and image initialization
- `srcs/my_mlx.c` — MiniLibX wrapper functions (pixel drawing, event handling)
- `srcs/drawing.c` — Drawing utilities (map, shapes, floor/ceiling)
- `srcs/render_rect.c` — 3D wall rendering with textures
- `srcs/texture_init.c` — Texture loading and initialization
- `srcs/rays.c` — Ray linked list management
- `srcs/rays_2.c` — Additional ray utilities
- `srcs/draw_ray.c` — Ray casting and distance calculation
- `srcs/dda.c` — DDA algorithm implementation
- `srcs/dda_2.c` — DDA utilities and initialization
- `srcs/movements.c` — Player movement and collision detection
- `srcs/ft_parsing_utils1.c` — Map file parsing (texture/color extraction)
- `srcs/ft_parsing_utils2.c` — Map validation
- `srcs/ft_parsing_utils3.c` — Map parsing utilities
- `srcs/ft_parsing_utils4.c` — Additional parsing helpers
- `srcs/ft_parsing_utils5.c` — Line reading and validation
- `srcs/ft_free.c` — Memory cleanup functions
- `srcs/tools.c` — Utility functions (file reading, extension checking)
- `includes/cub3D.h` — Main header with function prototypes
- `includes/structs.h` — Data structures (player, ray, window, config, DDA)
- `includes/libft/` — Custom utility library (required for compilation)
- `includes/mlx/` — MiniLibX graphics library (as a git submodule)
- `textures/` — Wall texture files (XPM format)
- `maps/` — Scene configuration files (`.cub` format)

---

## Compilation

A `Makefile` is provided.

### Available targets

```bash
make        # builds cub3D
make clean  # removes object files
make fclean # removes binaries and object files
make re     # full rebuild
```

### Dependencies

The project requires:
- MiniLibX library (included as submodule)
- X11 library (`-lX11`)
- Xext library (`-lXext`)
- Math library (`-lm`)

Install on Ubuntu/Debian:
```bash
sudo apt-get update
sudo apt-get install libx11-dev libxext-dev
```

---

## Notes

- **Raycasting algorithm:**
  1. For each vertical column of the screen, cast a ray from the player's position
  2. Use DDA to find the first wall intersection
  3. Calculate perpendicular distance to avoid fisheye effect
  4. Determine wall height based on distance
  5. Apply appropriate texture based on wall direction
  6. Render floor and ceiling colors

- **Game constants:**
  - Field of View: 50 degrees
  - Window size: 1080x720 pixels
  - Tile size: 128 pixels
  - Player directions: North (90°), South (270°), East (0°), West (180°)

- **Optimization:**
  - Rays are updated only when player moves or rotates
  - DDA algorithm efficiently finds wall intersections
  - Textures are pre-loaded at initialization

- **Controls:**
  - Movement uses collision detection to prevent walking through walls
  - Smooth rotation with arrow keys
  - ESC key properly frees all resources before exiting

- The project implements a custom `my_mlx_pixel_put` for efficient pixel manipulation.
