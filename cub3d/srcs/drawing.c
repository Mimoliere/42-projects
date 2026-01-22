/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:53:20 by bguerrou          #+#    #+#             */
/*   Updated: 2025/10/30 12:44:28 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_square(t_image *img, int x, int y, int color)
{
	int	i;
	int	j;
	int	color_printed;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			color_printed = color;
			if ((i == 0 || i == TILE_SIZE - 1 || j == 0 || j == TILE_SIZE - 1))
				color_printed = 0x000000;
			my_mlx_pixel_put(img, j + x, i + y, color_printed);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_player player, int color, t_image *minimap)
{
	int	x;
	int	y;
	int	radius;
	int	center_x;
	int	center_y;

	radius = TILE_SIZE / 8;
	center_x = TILE_SIZE / 2;
	center_y = TILE_SIZE / 2;
	y = -radius;
	while (y <= radius)
	{
		x = -radius;
		while (x <= radius)
		{
			if (x * x + y * y <= radius * radius)
				my_mlx_pixel_put(minimap,
					player.x + center_x + x,
					player.y + center_y + y, color);
			x++;
		}
		y++;
	}
}

void	draw_map(char **map, t_image *minimap, int height, t_window *window)
{
	int	i;
	int	j;
	int	used;

	(void) window;
	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				used = 0xFFFFFF;
			else if (map[i][j] == '0')
				used = 0x9DF071;
			draw_square(minimap, j * TILE_SIZE, i * TILE_SIZE, used);
			j++;
		}
		i++;
	}
}

void	draw_floor_ceiling(t_image *background, t_config *config)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(background, j, i, config->ceiling_color);
			j++;
		}
		i++;
	}
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			my_mlx_pixel_put(background, j, i, config->floor_color);
			j++;
		}
		i++;
	}
}
