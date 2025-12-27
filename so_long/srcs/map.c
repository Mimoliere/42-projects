/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:27:45 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 17:15:01 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	max_dimensions(char **map, int n)
{
	int	result;

	result = 0;
	if (n == 1)
		while (map[result])
			result++;
	else
		while (map[0][result])
			result++;
	return (result);
}

int	acceptable_chars(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	return (1);
}

int	count_elm(char **map, char element)
{
	int	row;
	int	column;
	int	count;

	row = -1;
	count = 0;
	while (map[++row])
	{
		column = -1;
		while (map[row][++column])
			if (map[row][column] == element)
				count++;
	}
	return (count);
}

void	clone_map(char **map, char **clone)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			clone[i][j] = map[i][j];
	}
}

int	find_char(char **map, int c, int which)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == c)
				break ;
		if (map[i][j] == c)
			break ;
	}
	if (which == 1)
		return (i);
	return (j);
}
