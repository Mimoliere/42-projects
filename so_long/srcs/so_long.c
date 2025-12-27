/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:18:58 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 17:14:34 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	window(t_appli *appli);
static int	keypress(int keycode, t_appli *appli);

int	main(int argc, char **argv)
{
	int		arglen;
	t_appli	appli;

	if (argc != 2)
		file_error();
	arglen = ft_strlen(argv[1]);
	if (arglen < 4 || ft_strncmp(argv[1] + arglen - 4, ".ber", 4))
		file_error();
	appli.map = check_map(argv[1]);
	if (!appli.map)
		return (-1);
	appli.count = 0;
	window(&appli);
	free_arr(appli.map);
	return (0);
}

static void	window(t_appli *appli)
{
	int		rows;
	int		columns;

	rows = max_dimensions(appli->map, 1);
	columns = max_dimensions(appli->map, 2);
	appli->mlx = mlx_init();
	if (!appli->mlx)
		return (free_exit(appli, 1));
	appli->win = mlx_new_window(appli->mlx, columns * 64, rows * 64, "so_long");
	if (!appli->win)
		return (free_exit(appli, 1));
	fill_map(appli, 32, 32);
	mlx_hook(appli->win, KeyPress, KeyPressMask, &keypress, appli);
	mlx_loop(appli->mlx);
}

static int	keypress(int keycode, t_appli *appli)
{
	int	i;
	int	move;

	if (keycode == 65307)
		free_exit(appli, 0);
	else if (keycode == 65362 || keycode == 119)
		move = move_player(appli->map, 1, appli);
	else if (keycode == 65363 || keycode == 100)
		move = move_player(appli->map, 2, appli);
	else if (keycode == 65361 || keycode == 97)
		move = move_player(appli->map, 3, appli);
	else if (keycode == 65364 || keycode == 115)
		move = move_player(appli->map, 4, appli);
	else
		move = 0;
	if (move == 1)
	{
		i = 0;
		while (i < 5)
			mlx_destroy_image(appli->mlx, appli->tiles[i++]);
		free(appli->tiles);
		fill_map(appli, 32, 32);
		ft_printf("%i steps\n", ++(appli->count));
	}
	return (0);
}
