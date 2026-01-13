/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 12:27:45 by bguerrou          #+#    #+#             */
/*   Updated: 2025/04/05 15:56:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	max_dimensions(char **map, int n)
{
	int	result;
	int	i;
	int	j;

	result = 0;
	if (n == 1)
		while (map[result])
			result++;
	else
		while (map[0][result])
			result++;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (n != 1 && j != result)
			return (0);
	}
	return (result);
}

int	acceptable_chars(char c)
{
	if (c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
		return (0);
	return (1);
}

int	count_element(char **map, char element)
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
