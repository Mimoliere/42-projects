/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:18:58 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/13 17:25:39 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
\
static int	check_files(void);
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
	if (!check_files())
		return (1);
	if (!appli.map)
		return (-1);
	appli.endcase = 0;
	appli.count = 0;
	window(&appli);
	free_arr(appli.map);
	return (0);
}

static int	check_files(void)
{
	int	fd[ASSETS_COUNT];
	int	ok;
	int	i;

	ok = 1;
	if (ASSETS_COUNT < 5)
		return (ft_putstr_fd("MISSING FILES.\n", 2), 0);
	fd[0] = open("assets/buddy2.xpm", O_RDONLY);
	fd[1] = open("assets/cat.xpm", O_RDONLY);
	fd[2] = open("assets/end.xpm", O_RDONLY);
	fd[3] = open("assets/ground.xpm", O_RDONLY);
	fd[4] = open("assets/tree.xpm", O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0 || fd[3] < 0 || fd[4] < 0)
		ok = 0;
	i = -1;
	while (++i < 5)
		if (fd[i] >= 0)
			close(fd[i]);
	if (!ok)
		ft_putstr_fd("Non valid image file.\n", 2);
	return (ok);
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
	appli->win = mlx_new_window(appli->mlx, columns * TILE_SIZE,
			rows * TILE_SIZE, "so_long");
	if (!appli->win)
		return (free_exit(appli, 1));
	fill_map(appli, 32, 32);
	mlx_hook(appli->win, KeyPress, KeyPressMask, &keypress, appli);
	mlx_hook(appli->win, 17, 1L << 2, &end, appli);
	mlx_loop(appli->mlx);
}

static int	keypress(int keycode, t_appli *appli)
{
	int	i;
	int	move;

	move = 0;
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
