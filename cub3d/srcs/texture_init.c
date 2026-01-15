/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 16:44:33 by alo               #+#    #+#             */
/*   Updated: 2025/10/30 14:35:25 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_texture(t_window *window, t_image *tex, char *path)
{
	tex->img = mlx_xpm_file_to_image(window->mlx,
			path, &tex->width, &tex->height);
	if (!tex->img)
	{
		ft_putstr_fd("Error\nFailed to load texture: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	tex->addr = mlx_get_data_addr(tex->img,
			&tex->bpp, &tex->line_length, &tex->endian);
}

void	init_sprites(t_window *window)
{
	if (!window->cfg.no || !window->cfg.so
		|| !window->cfg.we || !window->cfg.ea)
	{
		ft_putstr_fd("Error\nMissing texture path in config\n", 2);
		exit(1);
	}
	init_texture(window, &window->tex_no, window->cfg.no);
	init_texture(window, &window->tex_so, window->cfg.so);
	init_texture(window, &window->tex_we, window->cfg.we);
	init_texture(window, &window->tex_ea, window->cfg.ea);
}
