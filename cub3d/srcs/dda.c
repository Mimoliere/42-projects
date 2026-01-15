/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 21:46:13 by alo               #+#    #+#             */
/*   Updated: 2025/11/02 19:22:06 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_ray_pos(t_window *w, t_dda *d)
{
	d->pos_x = (w->player.x + TILE_SIZE / 2.0f) / (float)TILE_SIZE;
	d->pos_y = (w->player.y + TILE_SIZE / 2.0f) / (float)TILE_SIZE;
	d->map_x = (int)d->pos_x;
	d->map_y = (int)d->pos_y;
}

void	run_dda(t_window *w, t_dda *d)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (d->side_x < d->side_y)
		{
			d->side_x += d->delta_x;
			d->map_x += d->step_x;
			d->side = 0;
		}
		else
		{
			d->side_y += d->delta_y;
			d->map_y += d->step_y;
			d->side = 1;
		}
		if (is_a_wall(w, d->map_x * TILE_SIZE + 0.5f,
				d->map_y * TILE_SIZE + 0.5f))
			hit = 1;
	}
}

void	set_ray_hit(t_window *w, t_ray *r, t_dda *d, t_vector vector)
{
	float	dist_map;

	if (d->side == 0)
	{
		if (vector.rx == 0.0f)
			vector.rx = 1.00000000317107685E-30F;
		dist_map = (d->map_x - d->pos_x + (1 - d->step_x) / 2.0f) / vector.rx;
	}
	else
	{
		if (vector.ry == 0.0f)
			vector.ry = 1.00000000317107685E-30F;
		dist_map = (d->map_y - d->pos_y + (1 - d->step_y) / 2.0f) / vector.ry;
	}
	r->ray_length = fabsf(dist_map) * TILE_SIZE;
	r->hit_x = w->player.x + TILE_SIZE / 2.0f + vector.rx * r->ray_length;
	r->hit_y = w->player.y + TILE_SIZE / 2.0f + vector.ry * r->ray_length;
}

void	set_hit_dir(t_ray *r, t_dda *d, t_vector vector)
{
	if (d->side == 0)
	{
		r->hit_coord = fmodf(r->hit_y, TILE_SIZE);
		if (vector.rx > 0.0f)
			r->direction = DIR_WE;
		else
			r->direction = DIR_EA;
	}
	else
	{
		r->hit_coord = fmodf(r->hit_x, TILE_SIZE);
		if (vector.ry < 0.0f)
			r->direction = DIR_SO;
		else
			r->direction = DIR_NO;
	}
}

void	dda_cast_ray(t_window *w, t_ray *r, float angle)
{
	t_dda		d;
	t_vector	vector;

	vector = init_ray_dir(r, angle);
	init_ray_pos(w, &d);
	init_step(&d, vector.rx, vector.ry);
	run_dda(w, &d);
	set_ray_hit(w, r, &d, vector);
	set_hit_dir(r, &d, vector);
	r->ray_x = vector.rx;
	r->ray_y = vector.ry;
}
