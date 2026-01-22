/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:52:22 by bguerrou          #+#    #+#             */
/*   Updated: 2025/09/01 13:53:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *) dst = color;
}

int	loop_handle(t_window *window)
{
	refresh_window(window);
	return (0);
}

int	handle_keypress(int keycode, t_window *window)
{
	if (keycode == 65307)
		clear_exit(window, 0);
	if (keycode >= 0 && keycode < 65536)
		window->keys[keycode] = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_window *window)
{
	if (keycode >= 0 && keycode < 65536)
		window->keys[keycode] = 0;
	return (0);
}
