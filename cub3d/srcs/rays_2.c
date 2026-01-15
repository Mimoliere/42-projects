/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:48:19 by alo               #+#    #+#             */
/*   Updated: 2025/10/29 17:55:37 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	la_valeur_stp(t_ray *ray, float angle)
{
	float	rx;
	float	ry;

	rx = cos(angle * (PI / 180.0f));
	ry = -sin(angle * (PI / 180.0f));
	ray->ray_x = rx;
	ray->ray_y = ry;
	ray->angle = angle;
	ray->next = NULL;
}

void	init_rays(t_window *window)
{
	float	angle;
	float	step;
	int		column;
	t_ray	*new_ray;

	angle = window->player.direction + 35.0f;
	step = 70.0f / WIDTH;
	column = 0;
	window->rays = NULL;
	while (column < WIDTH)
	{
		new_ray = malloc(sizeof(t_ray));
		if (!new_ray)
			clear_exit(window, 1);
		la_valeur_stp(new_ray, angle);
		ray_add_back(&window->rays, new_ray);
		angle -= step;
		column++;
	}
	window->ray_nb = WIDTH;
}
