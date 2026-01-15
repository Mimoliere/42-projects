/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:23:14 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/07 00:10:01 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "structs.h"

# define FOV 50.0f
# define WIDTH 1080
# define HEIGHT 720
# define TILE_SIZE 128
# define NORTH 90
# define SOUTH 270
# define EAST 0
# define WEST 180
# define PI 3.14159265359

// cub3D.c
void		refresh_window(t_window *window);
int			is_a_wall(t_window *window, int x, int y);
void		clear_exit(t_window *window, int code);

// parsing(tous).c
char		*longest_line(char **lines);
int			check_map_closed(t_map *map, int x, int y);
int			parse_parameters(t_config *cfg, char *line);
int			parse_color(char *str);
void		free_split(char **tab);
int			is_mapline(char *line);
int			check_tout(t_config *cfg, char *file);
int			parse_map(t_config *cfg, char **lines);
int			check_map_closed(t_map *map, int px, int py);
char		*get_next_line(int fd);
void		ft_shiftmem(char *src, int size, int buffersize);
char		*ft_strnjoin(char *s1, char *s2, int size);
int			two_players(char **lines);

// init.c
void		init_window(t_window *window);
void		img_init(t_window *window);
int			max_width(char **map);

// my_mlx.c
void		my_mlx_pixel_put(t_image *img, int x, int y, int color);
int			loop_handle(t_window *window);
int			handle_keypress(int keycode, t_window *window);
int			handle_keyrelease(int keycode, t_window *window);

// drawing.c
void		draw_map(char **map, t_image *minimap, int height,
				t_window *window);
void		draw_square(t_image *img, int x, int y, int color);
void		render_rect(t_window *window);
void		draw_circle(t_player player, int color, t_image *minimap);
void		draw_floor_ceiling(t_image *background, t_config *config);

// texture_init.c
void		init_texture(t_window *window, t_image *tex, char *path);
void		init_sprites(t_window *window);

// rays.c
void		ray_add_back(t_ray **rays, t_ray *new);
int			nb_of_rays(t_ray *rays);
void		free_rays(t_ray *rays);
void		update_rays(t_window *window);
void		init_rays(t_window *window);

// draw_rays.c
void		check_ray_dir(t_ray *ray, float x, float y);
int			ray_dist(t_window *window, float x, float y);
t_ray		*make_ray(t_window *window, float x, float y, float angle);
void		draw_ray(t_window *window);

// movements.c
void		manage_moves(t_window *window);
void		movement(t_window *window, t_player *player, int kc, int dir);

// dda.c
void		dda_cast_ray(t_window *w, t_ray *r, float angle);
t_vector	init_ray_dir(t_ray *ray, float angle);
void		init_step(t_dda *d, float rx, float ry);

// free.c
void		free_config(t_config *config);
void		free_texture(void *mlx, t_image *texture);
void		free_map(t_map *map);
void		free_parsing(t_config *cfg);
void		memset_config(t_config *cfg);

// tools.c
void		argc_error(char *exe);
int			check_extension(char *file, char *ex);
char		**read_file(char *path);
int			end(t_window *window);

/* Grand merci à Salsabile et Sofiabile ainsi qu'à Oussamabile et
Rayanbile sans qui tout cela n'aurait pas été possible */

#endif
