/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:42:11 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/26 23:25:28 by bguerrou         ###   ########.fr       */
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
	while(map[0][column])
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
	int	lines;
	int	columns;
	int	max_lines;
	int	max_column;

	lines = -1;
	max_lines = max_dimensions(map, 1);
	max_column = max_dimensions(map, 0);
	if (max_column <= max_lines)
		return (free_arr(map), map_error(3));
	while (++lines < max_lines)
	{
		columns = -1;
		if (map[lines][++columns] != '1')
			return (free_arr(map), map_error(4));
		while (map[lines][++columns] && columns < max_column) {
			if ((lines == 0 || lines == max_lines - 1) && map[lines][columns] != '1')
				return (free_arr(map), map_error(4));
			if ((lines != 0 && lines != max_lines - 1) && !acceptable_chars(map[lines][columns]))
				return (free_arr(map), map_error(5));
		}
		if (columns != max_column || map[lines][columns - 1] != '1')
			return (free_arr(map), map_error(4));
	}
}

static void	finishable(char **clone, char **map)
{
	int	rows;
	int	columns;

	if (count_element(map, 'P') != 1 || count_element(map, 'E') != 1 || count_element(map, 'C') < 1)
		return (free_arr(map), free_arr(clone), map_error(6));
	rows = -1;
	while (clone[++rows])
	{
		columns = -1;
		while(clone[rows][++columns])
			if (clone[rows][columns] == 'P')
				break;
		if (clone[rows][columns] == 'P')
			break;
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
	if (count_element(clone, 'C') == 0 && count_element(clone, 'E') == 0)
        return (1);
	return (0);
}
