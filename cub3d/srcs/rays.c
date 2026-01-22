/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:53:50 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/07 00:13:56 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	update_rays(t_window *window)
{
	t_ray	*ray;
	float	angle;
	float	step;

	angle = window->player.direction + (FOV / 2.0f);
	step = FOV / (float)WIDTH;
	ray = window->rays;
	while (ray)
	{
		dda_cast_ray(window, ray, angle);
		angle -= step;
		ray = ray->next;
	}
}

void	set_rays(t_window *window, float angle)
{
	float	step;
	int		column;
	float	rx;
	float	ry;
	t_ray	*new_ray;

	step = 70.0f / WIDTH;
	column = 0;
	while (column < WIDTH)
	{
		rx = cos(angle * (PI / 180.0f));
		ry = -sin(angle * (PI / 180.0f));
		new_ray = malloc(sizeof(t_ray));
		if (!new_ray)
			clear_exit(window, 1);
		new_ray->ray_x = rx;
		new_ray->ray_y = ry;
		new_ray->angle = angle;
		new_ray->next = NULL;
		ray_add_back(&window->rays, new_ray);
		angle -= step;
		column++;
	}
	window->ray_nb = WIDTH;
}

void	ray_add_back(t_ray **rays, t_ray *new)
{
	t_ray	*temp;

	if (!*rays)
	{
		*rays = new;
		return ;
	}
	temp = *rays;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	nb_of_rays(t_ray *rays)
{
	int		count;
	t_ray	*curr;

	count = 0;
	curr = rays;
	while (curr)
	{
		count++;
		curr = curr->next;
	}
	return (count);
}

void	free_rays(t_ray *rays)
{
	if (!rays)
		return ;
	if (rays->next)
		free_rays(rays->next);
	free(rays);
	rays = NULL;
}
