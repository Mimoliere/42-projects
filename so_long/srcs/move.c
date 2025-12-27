/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:19:34 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:46:02 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	end_game(char **map, int direction, t_appli *appli);

int	move_player(char **map, int direction, t_appli *appli)
{
	int	row;
	int	column;

	row = find_char(map, 'P', 1);
	column = find_char(map, 'P', 0);
	end_game(map, direction, appli);
	if (direction == 1 && map[row - 1][column] != '1' && map[row - 1][column] != 'E')
		map[row - 1][column] = 'P';
	else if (direction == 2 && map[row][column + 1] != '1' && map[row][column + 1] != 'E')
		map[row][column + 1] = 'P';
	else if (direction == 3 && map[row][column - 1] != '1' && map[row][column - 1] != 'E')
		map[row][column - 1] = 'P';
	else if (direction == 4 && map[row + 1][column] != '1' && map[row + 1][column] != 'E')
		map[row + 1][column] = 'P';
	else
		return (0);
	map[row][column] = '0';
	return (1);
}

static void	end_game(char **map, int direction, t_appli *appli)
{
	int	row;
	int	column;

	row = find_char(map, 'P', 1);
	column = find_char(map, 'P', 0);
	if (direction == 1 && map[row - 1][column] == 'E' && !count_element(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 2 && map[row][column + 1] == 'E' && !count_element(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 3 && map[row][column - 1] == 'E' && !count_element(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 4 && map[row + 1][column] == 'E' && !count_element(map, 'C'))
		free_exit(appli, 0);
}
