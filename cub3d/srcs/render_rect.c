/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:20:21 by alo               #+#    #+#             */
/*   Updated: 2025/10/30 13:51:55 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

t_image	*get_tex(t_ray *r, t_window *w)
{
	if (r->direction == DIR_NO)
		return (&w->tex_no);
	if (r->direction == DIR_SO)
		return (&w->tex_so);
	if (r->direction == DIR_WE)
		return (&w->tex_we);
	return (&w->tex_ea);
}

int	get_tex_x(t_ray *r, t_image *tex)
{
	int	x;

	x = (int)((r->hit_coord / TILE_SIZE) * tex->width);
	if (r->direction == DIR_NO || r->direction == DIR_EA)
		x = tex->width - 1 - x;
	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	return (x);
}

void	draw_column_loop(t_window *window, int col, t_column *col_data)
{
	int		y;
	int		tex_y;

	y = col_data->y;
	while (y < HEIGHT && y <= HEIGHT / 2 + col_data->rect_h / 2)
	{
		tex_y = (int)((y - (HEIGHT / 2 - col_data->rect_h / 2))
				* ((float)col_data->tex->height / col_data->rect_h));
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= col_data->tex->height)
			tex_y = col_data->tex->height - 1;
		my_mlx_pixel_put(&window->background, col, y,
			*(int *)(col_data->tex->addr + tex_y
				* col_data->tex->line_length + col_data->tex_x
				* (col_data->tex->bpp / 8)));
		y++;
	}
}

void	draw_column(t_window *window, t_ray *ray, int col)
{
	t_column	col_data;

	if (ray->ray_length <= 0)
		ray->ray_length = 0.0001f;
	col_data.corr = cosf((ray->angle - window->player.direction)
			* (PI / 180.0f));
	col_data.rect_h = (int)((TILE_SIZE / (ray->ray_length * col_data.corr))
			* ((WIDTH / 2) / tan(35.0f * (PI / 180.0f))));
	col_data.y = HEIGHT / 2 - col_data.rect_h / 2;
	if (col_data.y < 0)
		col_data.y = 0;
	col_data.tex = get_tex(ray, window);
	col_data.tex_x = get_tex_x(ray, col_data.tex);
	draw_column_loop(window, col, &col_data);
}

void	render_rect(t_window *window)
{
	t_ray	*curr;
	int		c;

	curr = window->rays;
	c = 0;
	while (curr && c < window->ray_nb)
	{
		draw_column(window, curr, c);
		curr = curr->next;
		c++;
	}
}
