/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:42:11 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 17:13:48 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	is_valid_map(char **map, int fd);
static void	borders(char **map);
static void	finishable(char **clone, char **map);
static int	recursive_path(char **clone, int row, int column, char **map);

char	**check_map(char *file)
{
	char	*str;
	int		fd;
	char	*tmp;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Non existing file.\n", 2), NULL);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), NULL);
	tmp = get_next_line(fd);
	while (tmp)
	{
		str = altered_ft_strjoin(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	map = ft_split(str, '\n');
	free(str);
	if (!map)
		return (close(fd), NULL);
	is_valid_map(map, fd);
	return (map);
}

static void	is_valid_map(char **map, int fd)
{
	int		row;
	int		column;
	char	**clone;

	close(fd);
	borders(map);
	row = 0;
	column = 0;
	while (map[row])
		row++;
	while (map[0][column])
		column++;
	clone = ft_calloc(row + 1, sizeof(char *));
	if (!clone)
		return (free_arr(map), map_error(2));
	while (--row >= 0)
	{
		clone[row] = ft_strdup(map[row]);
		if (!clone[row])
			return (free_arr(map), free_arr(clone), map_error(2));
	}
	finishable(clone, map);
	free_arr(clone);
}

static void	borders(char **map)
{
	int	l;
	int	c;
	int	max_l;
	int	max_c;

	l = -1;
	max_l = max_dimensions(map, 1);
	max_c = max_dimensions(map, 0);
	if (max_c <= max_l)
		return (free_arr(map), map_error(3));
	while (++l < max_l)
	{
		c = -1;
		if (map[l][++c] != '1')
			return (free_arr(map), map_error(4));
		while (map[l][++c] && c < max_c)
		{
			if ((l == 0 || l == max_l - 1) && map[l][c] != '1')
				return (free_arr(map), map_error(4));
			if ((l != 0 && l != max_l - 1) && !acceptable_chars(map[l][c]))
				return (free_arr(map), map_error(5));
		}
		if (c != max_c || map[l][c - 1] != '1')
			return (free_arr(map), map_error(4));
	}
}

static void	finishable(char **clone, char **map)
{
	int	rows;
	int	columns;

	if (count_elm(map, 'P') != 1 || count_elm(map, 'E') != 1
		|| count_elm(map, 'C') < 1)
		return (free_arr(map), free_arr(clone), map_error(6));
	rows = 0;
	columns = 0;
	while (clone[rows] && clone[rows][columns] != 'P')
	{
		while (clone[rows][columns] && clone[rows][columns] != 'P')
			columns++;
		if (clone[rows][columns] != 'P')
		{
			rows++;
			columns = 0;
		}
	}
	if (!recursive_path(clone, rows, columns, map))
		return (free_arr(map), free_arr(clone), map_error(7));
}

static int	recursive_path(char **clone, int row, int column, char **map)
{
	clone[row][column] = 'T';
	if (clone[row + 1][column] != '1' && clone[row + 1][column] != 'T')
		recursive_path(clone, row + 1, column, map);
	if (clone[row - 1][column] != '1' && clone[row - 1][column] != 'T')
		recursive_path(clone, row - 1, column, map);
	if (clone[row][column + 1] != '1' && clone[row][column + 1] != 'T')
		recursive_path(clone, row, column + 1, map);
	if (clone[row][column - 1] != '1' && clone[row][column - 1] != 'T')
		recursive_path(clone, row, column - 1, map);
	if (count_elm(clone, 'C') == 0 && count_elm(clone, 'E') == 0)
		return (1);
	return (0);
}
