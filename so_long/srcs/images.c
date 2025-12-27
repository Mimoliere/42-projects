/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 16:28:54 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/27 17:11:37 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	**initiate_images(t_appli *appli, int *w, int *h);
static int	which_image(char element);

void	fill_map(t_appli *appli, int width, int height)
{
	int		row;
	int		column;
	int		x;
	int		y;

	y = 0;
	row = -1;
	appli->tiles = initiate_images(appli, &width, &height);
	while (appli->map[++row])
	{
		column = -1;
		x = 0;
		while (appli->map[row][++column])
		{
			mlx_put_image_to_window(appli->mlx, appli->win,
				appli->tiles[which_image(appli->map[row][column])], x, y);
			x += height;
		}
		y += width;
	}
}

// Merci à Capupu et Alexis pour les sprites
static void	**initiate_images(t_appli *appli, int *w, int *h)
{
	void	**tiles;

	tiles = malloc(sizeof(void *) * (6));
	if (!tiles)
		free_exit(appli, 5);
	tiles[0] = mlx_xpm_file_to_image(appli->mlx, "assets/ground.xpm", w, h);
	if (!tiles[0])
		free_exit(appli, 4);
	tiles[1] = mlx_xpm_file_to_image(appli->mlx, "assets/tree.xpm", w, h);
	if (!tiles[1])
		free_exit(appli, 4);
	tiles[2] = mlx_xpm_file_to_image(appli->mlx, "assets/buddy2.xpm", w, h);
	if (!tiles[2])
		free_exit(appli, 4);
	tiles[3] = mlx_xpm_file_to_image(appli->mlx, "assets/cat.xpm", w, h);
	if (!tiles[3])
		free_exit(appli, 4);
	tiles[4] = mlx_xpm_file_to_image(appli->mlx, "assets/end.xpm", w, h);
	if (!tiles[4])
		free_exit(appli, 4);
	return (tiles);
}

static int	which_image(char element)
{
	if (element == '0')
		return (0);
	if (element == '1')
		return (1);
	if (element == 'P')
		return (2);
	if (element == 'C')
		return (3);
	if (element == 'E')
		return (4);
	return (0);
}
