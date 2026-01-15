/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 13:55:05 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/07 00:13:18 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	manage_moves(t_window *window)
{
	if (window->keys[65362] == 1 || window->keys[119] == 1)
		movement(window, &window->player, 65362, window->player.direction);
	if (window->keys[65364] == 1 || window->keys[115] == 1)
		movement(window, &window->player, 65364, window->player.direction);
	if (window->keys[100] == 1)
		movement(window, &window->player, 100, window->player.direction);
	if (window->keys[97] == 1)
		movement(window, &window->player, 97, window->player.direction);
	if (window->keys[65363] == 1)
		window->player.direction -= 1;
	if (window->keys[65361] == 1)
		window->player.direction += 1;
}

void	lateral_movement(t_window *window, t_player *player, int sign, int dir)
{
	float	try_x;
	float	try_y;
	float	move_speed;

	move_speed = 5.0f;
	try_x = player->x + sign * move_speed * cosf(dir * (PI / 180) - (PI / 2));
	try_y = player->y + sign * move_speed * sinf(dir * (PI / 180) + (PI / 2));
	if (!is_a_wall(window, try_x + TILE_SIZE / 2, player->y + TILE_SIZE / 2))
		player->x = try_x;
	if (!is_a_wall(window, player->x + TILE_SIZE / 2, try_y + TILE_SIZE / 2))
		player->y = try_y;
}

void	movement(t_window *window, t_player *player, int kc, int dir)
{
	int		sign;
	float	move_speed;
	float	try_x;
	float	try_y;

	move_speed = 5.0f;
	if (kc == 65362 || kc == 119 || kc == 100)
		sign = 1;
	if (kc == 65364 || kc == 115 || kc == 97)
		sign = -1;
	if (kc == 100 || kc == 97)
	{
		lateral_movement(window, player, sign, dir);
	}
	if (kc == 65362 || kc == 119 || kc == 65364 || kc == 115)
	{
		try_x = player->x + sign * move_speed * cos(dir * (PI / 180));
		try_y = player->y - sign * move_speed * sin(dir * (PI / 180));
		if (!is_a_wall(window, try_x + TILE_SIZE / 2,
				player->y + TILE_SIZE / 2))
			player->x = try_x;
		if (!is_a_wall(window, player->x + TILE_SIZE / 2,
				try_y + TILE_SIZE / 2))
			player->y = try_y;
	}
}
