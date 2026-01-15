/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:55:44 by alo               #+#    #+#             */
/*   Updated: 2025/11/04 16:21:28 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	ft_shiftmem(char *src, int size, int buffersize)
{
	int	i;

	i = -1;
	while (++i + size < buffersize)
		src[i] = src[i + size];
	while (i < buffersize)
		src[i++] = 0;
}

int	two_players(char **lines)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = -1;
	while (lines[++i])
	{
		j = -1;
		while (lines[i][++j])
		{
			if (lines[i][j] == 'E' || lines[i][j] == 'S'
				|| lines[i][j] == 'W' || lines[i][j] == 'N')
				player++;
		}
	}
	return (player != 1);
}

int	set_player_pos(t_config *cfg, int j, int i)
{
	while (cfg->map.grid[i][j])
	{
		if (ft_strchr("NSEW", cfg->map.grid[i][j]))
		{
			if (cfg->player_dir != 0)
				return (0);
			cfg->player_x = j;
			cfg->player_y = i;
			cfg->player_dir = cfg->map.grid[i][j];
			cfg->map.grid[i][j] = '0';
		}
		j++;
	}
	return (1);
}

int	parse_map2(t_config *cfg, char **lines, int i)
{
	int		j;

	while (lines[i])
	{
		cfg->map.grid[i] = ft_strdup(lines[i]);
		if (!cfg->map.grid[i])
			return (free_arr(cfg->map.grid, i), free_config(cfg), exit(-1), 0);
		j = 0;
		if (!set_player_pos(cfg, j, i))
			return (0);
		i++;
	}
	return (i);
}

int	parse_map(t_config *cfg, char **lines)
{
	int		i;

	i = 0;
	if (two_players(lines))
		return (0);
	cfg->map.height = 0;
	while (lines[cfg->map.height])
		cfg->map.height++;
	cfg->map.grid = malloc(sizeof(char *) * (cfg->map.height + 1));
	if (!cfg->map.grid)
		return (0);
	i = parse_map2(cfg, lines, i);
	cfg->map.grid[i] = NULL;
	return (check_map_closed(&cfg->map, cfg->player_x, cfg->player_y));
}
