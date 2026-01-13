/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:26:53 by bguerrou          #+#    #+#             */
/*   Updated: 2025/04/05 15:22:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	file_error(void)
{
	ft_putstr_fd("Enter a valid file please (*.ber).\n", 2);
	exit(1);
}

void	map_error(void)
{
	ft_putstr_fd("Map is not valid.\n", 2);
	exit(2);
}

void	free_exit(t_appli *appli, int code)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_destroy_image(appli->mlx, appli->tiles[i++]);
	free(appli->tiles);
	mlx_destroy_window(appli->mlx, appli->win);
	mlx_destroy_display(appli->mlx);
	free_arr(appli->map);
	free(appli->mlx);
	exit(code);
}

int	end(t_appli *appli)
{
	free_exit(appli, 0);
	return (0);
}
