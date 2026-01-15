/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 15:40:38 by alo               #+#    #+#             */
/*   Updated: 2025/10/30 15:27:21 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	is_outside(t_map *map, int x, int y)
{
	return (x < 0 || y < 0 || y >= map->height
		|| x >= (int)ft_strlen(map->grid[y]));
}

int	is_space_or_void(t_map *map, int x, int y)
{
	if (is_outside(map, x, y))
		return (1);
	return (map->grid[y][x] == ' ');
}

int	flood_fill(t_map *map, int x, int y, int **visited)
{
	if (is_outside(map, x, y))
		return (0);
	if (map->grid[y][x] == ' ')
		return (0);
	if (map->grid[y][x] == '1')
		return (1);
	if (visited[y][x])
		return (1);
	if (is_space_or_void(map, x + 1, y + 1)
		|| is_space_or_void(map, x - 1, y - 1)
		|| is_space_or_void(map, x + 1, y - 1)
		|| is_space_or_void(map, x - 1, y + 1))
		return (0);
	visited[y][x] = 1;
	return (flood_fill(map, x + 1, y, visited)
		&& flood_fill(map, x - 1, y, visited)
		&& flood_fill(map, x, y + 1, visited)
		&& flood_fill(map, x, y - 1, visited)
		&& flood_fill(map, x + 1, y + 1, visited)
		&& flood_fill(map, x - 1, y - 1, visited)
		&& flood_fill(map, x - 1, y + 1, visited)
		&& flood_fill(map, x + 1, y - 1, visited));
}

int	check_map_closed(t_map *map, int x, int y)
{
	int		**visited;
	int		i;
	int		res;

	visited = malloc(sizeof(int *) * map->height);
	i = 0;
	while (i < map->height)
	{
		visited[i] = calloc(ft_strlen(map->grid[i]), sizeof(int));
		i++;
	}
	res = flood_fill(map, x, y, visited);
	i = 0;
	while (i < map->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
	return (res);
}

char	*longest_line(char **lines)
{
	int		i;
	char	*longest;

	i = 0;
	longest = lines[i++];
	while (lines[i])
	{
		if (ft_strlen(lines[i]) > ft_strlen(longest))
			longest = lines[i];
		i++;
	}
	return (longest);
}
