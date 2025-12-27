/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:26:53 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/26 23:29:43 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	file_error(void)
{
	ft_putstr_fd("Enter a valid file please (*.ber).\n", 2);
	exit(1);
}

void	map_error(int code)
{
	ft_putstr_fd("Map is not valid.\n", 2);
	if (code == 2)
		ft_putstr_fd("Allocation error.\n", 2);
	if (code == 3)
		ft_putstr_fd("Non rectangular map.\n", 2);
	if (code == 4)
		ft_putstr_fd("Non closed map.\n", 2);
	if (code == 5)
		ft_putstr_fd("Non valid character in map.\n", 2);
	if (code == 6)
		ft_putstr_fd("Non valid amount of elements in map.\n", 2);
	if (code == 7)
		ft_putstr_fd("Non completable map.\n", 2);
	exit(code);
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
