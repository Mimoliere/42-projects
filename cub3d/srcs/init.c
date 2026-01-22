/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:50:48 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/07 13:49:35 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	set_keys(t_window *window)
{
	int	i;

	i = 0;
	while (i < 65536)
		window->keys[i++] = 0;
}

void	init_window(t_window *window)
{
	set_keys(window);
	window->mlx = mlx_init();
	if (window->mlx == NULL)
		return (free(window->mlx), exit(1));
	window->win = mlx_new_window(window->mlx,
			WIDTH, HEIGHT, "Cub3D");
	if (window->win == NULL)
		return (mlx_destroy_display(window->mlx), free(window->mlx), exit(1));
	init_sprites(window);
	img_init(window);
	init_rays(window);
	update_rays(window);
	window->ray_nb = nb_of_rays(window->rays);
	draw_floor_ceiling(&window->background, &window->cfg);
	mlx_put_image_to_window(window->mlx, window->win,
		window->background.img, 0, 0);
	mlx_hook(window->win, KeyPress, KeyPressMask, &handle_keypress, window);
	mlx_hook(window->win, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, window);
	mlx_hook(window->win, 17, 1L << 2, &end, window);
	mlx_loop_hook(window->mlx, &loop_handle, window);
	mlx_loop(window->mlx);
}

void	img_init(t_window *window)
{
	t_image	*background;

	background = &window->background;
	background->img = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	background->addr = mlx_get_data_addr(background->img, &background->bpp,
			&background->line_length, &background->endian);
}

int	max_width(char **map)
{
	int	i;
	int	len;
	int	max;

	if (!map)
		return (0);
	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
