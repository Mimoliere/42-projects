/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 13:17:53 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/26 22:37:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include <math.h>
# include <fcntl.h>

# define WINDOW_WIDTH 1620
# define WINDOW_HEIGHT 1050

typedef struct s_appli {
	void	*mlx;
	void	*win;
	char	**map;
	void	**tiles;
	int		count;
}			t_appli;

void	file_error(void);
void	map_error(int code);
void	free_exit(t_appli *appli, int code);
char	**check_map(char *file);
void	fill_map(t_appli *appli, int width, int height);
int		max_dimensions(char **map, int n);
int		acceptable_chars(char c);
int		count_element(char **map, char element);
void	clone_map(char **map, char **clone);
int		find_char(char **map, int c, int which);
int		move_player(char **map, int direction, t_appli *appli);

#endif
