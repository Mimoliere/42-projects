/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:19:34 by bguerrou          #+#    #+#             */
/*   Updated: 2025/04/14 14:25:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	end_game(char **map, int direction, t_appli *appli)
{
	int	row;
	int	column;

	row = find_char(map, 'P', 1);
	column = find_char(map, 'P', 0);
	if (direction == 1 && map[row - 1][column] == 'E'
			&& !count_element(map, 'C'))
		return (ft_printf("%i steps\n", ++(appli->count)), free_exit(appli, 0));
	else if (direction == 2 && map[row][column + 1] == 'E'
			&& !count_element(map, 'C'))
		return (ft_printf("%i steps\n", ++(appli->count)), free_exit(appli, 0));
	else if (direction == 3 && map[row][column - 1] == 'E'
			&& !count_element(map, 'C'))
		return (ft_printf("%i steps\n", ++(appli->count)), free_exit(appli, 0));
	else if (direction == 4 && map[row + 1][column] == 'E'
			&& !count_element(map, 'C'))
		return (ft_printf("%i steps\n", ++(appli->count)), free_exit(appli, 0));
}

static char	set_next(t_appli *appli, int row, int column)
{
	int	player_row;
	int	player_column;

	player_row = find_char(appli->map, 'P', 1);
	player_column = find_char(appli->map, 'P', 0);
	if (appli->endcase == 1)
	{
		appli->map[player_row][player_column] = 'E';
		appli->endcase = 0;
	}
	else
		appli->map[player_row][player_column] = '0';
	if (appli->map[row][column] == 'E')
		appli->endcase = 1;
	return ('P');
}

int	move_player(char **map, int direction, t_appli *appli)
{
	int	row;
	int	column;

	row = find_char(map, 'P', 1);
	column = find_char(map, 'P', 0);
	end_game(map, direction, appli);
	if (direction == 1 && map[row - 1][column] != '1')
		map[row - 1][column] = set_next(appli, row - 1, column);
	else if (direction == 2 && map[row][column + 1] != '1')
		map[row][column + 1] = set_next(appli, row, column + 1);
	else if (direction == 3 && map[row][column - 1] != '1')
		map[row][column - 1] = set_next(appli, row, column - 1);
	else if (direction == 4 && map[row + 1][column] != '1')
		map[row + 1][column] = set_next(appli, row + 1, column);
	else
		return (0);
	return (1);
}
