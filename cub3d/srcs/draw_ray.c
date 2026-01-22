/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:28:11 by alo               #+#    #+#             */
/*   Updated: 2025/10/30 13:48:00 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ray_dist(t_window *window, float x, float y)
{
	int	i;

	i = 0;
	while (!is_a_wall(window, window->player.x + TILE_SIZE / 2 + x * i,
			window->player.y + TILE_SIZE / 2 + y * i))
		i++;
	return (i);
}

void	check_ray_dir(t_ray *ray, float x, float y)
{
	if (fabs(fmod(ray->hit_x, TILE_SIZE)) < 0.0001f)
	{
		ray->hit_coord = fmod(ray->hit_y, TILE_SIZE);
		if (x > 0)
			ray->direction = DIR_EA;
		else
			ray->direction = DIR_WE;
	}
	else
	{
		ray->hit_coord = fmod(ray->hit_x, TILE_SIZE);
		if (y < 0)
			ray->direction = DIR_NO;
		else
			ray->direction = DIR_SO;
	}
	if (ray->hit_coord < 0)
		ray->hit_coord += TILE_SIZE;
}

t_ray	*make_ray(t_window *window, float x, float y, float angle)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		clear_exit(window, 1);
	ray->hit_x = window->player.x + TILE_SIZE / 2 + x * ray_dist(window, x, y);
	ray->hit_y = window->player.y + TILE_SIZE / 2 + y * ray_dist(window, x, y);
	ray->ray_x = x;
	ray->ray_y = y;
	ray->ray_length = ray_dist(window, x, y);
	ray->angle = angle;
	ray->next = NULL;
	check_ray_dir(ray, x, y);
	return (ray);
}

void	draw_ray(t_window *window)
{
	float	angle;
	float	step;
	int		column;
	float	rx;
	float	ry;

	angle = window->player.direction + 35.0f;
	step = 70.0f / WIDTH;
	column = 0;
	window->rays = NULL;
	while (column < WIDTH)
	{
		rx = cos(angle * (PI / 180.0f));
		ry = -sin(angle * (PI / 180.0f));
		ray_add_back(&window->rays, make_ray(window, rx, ry, angle));
		angle -= step;
		column++;
	}
	window->ray_nb = WIDTH;
}
