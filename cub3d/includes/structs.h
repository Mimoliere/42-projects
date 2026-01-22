/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:49:16 by bguerrou          #+#    #+#             */
/*   Updated: 2025/10/20 14:08:23 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "cub3D.h"

typedef enum e_dir
{
	DIR_NO,
	DIR_SO,
	DIR_WE,
	DIR_EA
}	t_dir;

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}			t_map;

typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor_color;
	int		ceiling_color;
	int		player_x;
	int		player_y;
	char	player_dir;
	t_map	map;
}			t_config;

typedef struct s_player
{
	float	x;
	float	y;
	float	direction;
}			t_player;

typedef struct s_ray
{
	float			ray_x;
	float			ray_y;
	float			hit_x;
	float			hit_y;
	float			ray_length;
	float			hit_coord;
	float			angle;
	int				direction;
	struct s_ray	*next;
}			t_ray;

typedef struct s_dda
{
	float	pos_x;
	float	pos_y;
	int		map_x;
	int		map_y;
	float	delta_x;
	float	delta_y;
	float	side_x;
	float	side_y;
	int		step_x;
	int		step_y;
	int		side;
}			t_dda;

typedef struct s_vector
{
	float	rx;
	float	ry;
}			t_vector;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_window
{
	void		*mlx;
	void		*win;
	char		**map;
	int			keys[65536];
	int			ray_nb;
	int			floor_color;
	int			ceiling_color;
	int			height;
	int			width;
	t_player	player;
	t_ray		*rays;
	t_image		background;
	t_image		minimap;
	t_config	cfg;
	t_image		tex_no;
	t_image		tex_so;
	t_image		tex_we;
	t_image		tex_ea;
}				t_window;

typedef struct s_column
{
	int		rect_h;
	int		y;
	t_image	*tex;
	int		tex_x;
	float	corr;
}	t_column;

#endif
