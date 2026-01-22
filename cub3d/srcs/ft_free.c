/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:28:00 by alo               #+#    #+#             */
/*   Updated: 2025/10/30 13:44:03 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_parsing(t_config *cfg)
{
	free_config(cfg);
	free_map(&cfg->map);
}

void	memset_config(t_config *cfg)
{
	if (!cfg)
		return ;
	cfg->no = NULL;
	cfg->so = NULL;
	cfg->we = NULL;
	cfg->ea = NULL;
	cfg->floor_color = 0;
	cfg->ceiling_color = 0;
	cfg->player_x = 0;
	cfg->player_y = 0;
	cfg->player_dir = 0;
	cfg->map.grid = NULL;
	cfg->map.width = 0;
	cfg->map.height = 0;
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (!map || !map->grid)
		return ;
	while (i < map->height)
	{
		if (map->grid[i])
			free(map->grid[i]);
		i++;
	}
	free(map->grid);
	map->grid = NULL;
	map->width = 0;
	map->height = 0;
}

void	free_config(t_config *config)
{
	if (!config)
		return ;
	if (config->no)
		free(config->no);
	if (config->so)
		free(config->so);
	if (config->we)
		free(config->we);
	if (config->ea)
		free(config->ea);
	config->floor_color = 0;
	config->ceiling_color = 0;
	config->player_x = 0;
	config->player_y = 0;
	config->player_dir = 0;
}

void	free_texture(void *mlx, t_image *texture)
{
	mlx_destroy_image(mlx, texture->img);
	texture->bpp = 0;
	texture->endian = 0;
	texture->height = 0;
	texture->width = 0;
	texture->line_length = 0;
}
