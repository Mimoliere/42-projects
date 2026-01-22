/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:10:03 by alo               #+#    #+#             */
/*   Updated: 2025/10/29 15:22:56 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_vector	init_ray_dir(t_ray *ray, float angle)
{
	t_vector	vector;

	vector.rx = cosf(angle * (PI / 180.0f));
	vector.ry = -sinf(angle * (PI / 180.0f));
	ray->angle = angle;
	return (vector);
}

void	init_step_x(t_dda *d, float rx)
{
	if (rx == 0.0f)
		d->delta_x = 1.00000001504746622E30F;
	else
		d->delta_x = fabsf(1.0f / rx);
	if (rx < 0)
	{
		d->step_x = -1;
		d->side_x = (d->pos_x - d->map_x) * d->delta_x;
	}
	else
	{
		d->step_x = 1;
		d->side_x = ((d->map_x + 1) - d->pos_x) * d->delta_x;
	}
}

void	init_step_y(t_dda *d, float ry)
{
	if (ry == 0.0f)
		d->delta_y = 1.00000001504746622E30F;
	else
		d->delta_y = fabsf(1.0f / ry);
	if (ry < 0)
	{
		d->step_y = -1;
		d->side_y = (d->pos_y - d->map_y) * d->delta_y;
	}
	else
	{
		d->step_y = 1;
		d->side_y = ((d->map_y + 1) - d->pos_y) * d->delta_y;
	}
}

void	init_step(t_dda *d, float rx, float ry)
{
	init_step_x(d, rx);
	init_step_y(d, ry);
}
