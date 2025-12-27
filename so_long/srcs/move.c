/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 00:19:34 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 17:14:05 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	end_game(char **map, int direction, t_appli *appli);

int	move_player(char **map, int direction, t_appli *appli)
{
	int	r;
	int	c;

	r = find_char(map, 'P', 1);
	c = find_char(map, 'P', 0);
	end_game(map, direction, appli);
	if (direction == 1 && map[r - 1][c] != '1' && map[r - 1][c] != 'E')
		map[r - 1][c] = 'P';
	else if (direction == 2 && map[r][c + 1] != '1' && map[r][c + 1] != 'E')
		map[r][c + 1] = 'P';
	else if (direction == 3 && map[r][c - 1] != '1' && map[r][c - 1] != 'E')
		map[r][c - 1] = 'P';
	else if (direction == 4 && map[r + 1][c] != '1' && map[r + 1][c] != 'E')
		map[r + 1][c] = 'P';
	else
		return (0);
	map[r][c] = '0';
	return (1);
}

static void	end_game(char **map, int direction, t_appli *appli)
{
	int	r;
	int	c;

	r = find_char(map, 'P', 1);
	c = find_char(map, 'P', 0);
	if (direction == 1 && map[r - 1][c] == 'E' && !count_elm(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 2 && map[r][c + 1] == 'E' && !count_elm(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 3 && map[r][c - 1] == 'E' && !count_elm(map, 'C'))
		free_exit(appli, 0);
	else if (direction == 4 && map[r + 1][c] == 'E' && !count_elm(map, 'C'))
		free_exit(appli, 0);
}
