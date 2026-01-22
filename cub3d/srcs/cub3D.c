/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 15:05:12 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/07 13:55:51 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	assign_direction(t_player *player, char dir);
void	clear_exit(t_window *window, int code);

int	main(int argc, char **argv)
{
	t_config	cfg;
	t_window	window;

	if (argc != 2)
		return (argc_error(argv[0]), 1);
	memset_config(&cfg);
	if (!check_tout(&cfg, argv[1]))
		return (1);
	window.player.x = cfg.player_x * TILE_SIZE;
	window.player.y = cfg.player_y * TILE_SIZE;
	assign_direction(&window.player, cfg.player_dir);
	cfg.map.grid[cfg.player_y][cfg.player_x] = '0';
	window.floor_color = cfg.floor_color;
	window.ceiling_color = cfg.ceiling_color;
	window.map = cfg.map.grid;
	window.height = cfg.map.height;
	window.width = max_width(window.map);
	window.cfg = cfg;
	init_window(&window);
}

void	assign_direction(t_player *player, char dir)
{
	if (dir == 'N')
		player->direction = NORTH;
	if (dir == 'S')
		player->direction = SOUTH;
	if (dir == 'E')
		player->direction = EAST;
	if (dir == 'W')
		player->direction = WEST;
}

void	refresh_window(t_window *window)
{
	t_image	background;

	manage_moves(window);
	update_rays(window);
	background.img = window->background.img;
	background.addr = window->background.addr;
	background.bpp = window->background.bpp;
	background.line_length = window->background.line_length;
	background.endian = window->background.endian;
	draw_floor_ceiling(&background, &window->cfg);
	render_rect(window);
	mlx_put_image_to_window(window->mlx, window->win,
		window->background.img, 0, 0);
}

int	is_a_wall(t_window *window, int x, int y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || x >= window->width * TILE_SIZE || y < 0
		|| y >= window->height * TILE_SIZE)
		return (1);
	map_x = x / TILE_SIZE;
	map_y = y / TILE_SIZE;
	if (map_x < 0 || map_x >= window->width
		|| map_y < 0 || map_y >= window->height)
		return (1);
	if (window->map[map_y][map_x] == '1')
		return (1);
	return (0);
}

void	clear_exit(t_window *window, int code)
{
	free_texture(window->mlx, &window->tex_ea);
	free_texture(window->mlx, &window->tex_we);
	free_texture(window->mlx, &window->tex_so);
	free_texture(window->mlx, &window->tex_no);
	mlx_destroy_image(window->mlx, window->background.img);
	free_arr(window->map, window->height);
	free_config(&window->cfg);
	free_rays(window->rays);
	mlx_destroy_window(window->mlx, window->win);
	mlx_destroy_display(window->mlx);
	free(window->mlx);
	window->width = 0;
	window->height = 0;
	window->floor_color = 0;
	window->ceiling_color = 0;
	window->ray_nb = 0;
	exit(code);
}
