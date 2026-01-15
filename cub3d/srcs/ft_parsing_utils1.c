/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:07:13 by alo               #+#    #+#             */
/*   Updated: 2025/11/11 14:45:26 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	dup_texture(int face, char *path, t_config *cfg)
{
	if (face == 1)
	{
		cfg->no = ft_strdup(path);
		if (!cfg->no)
			return (0);
	}
	else if (face == 2)
	{
		cfg->so = ft_strdup(path);
		if (!cfg->no)
			return (0);
	}
	else if (face == 3)
	{
		cfg->we = ft_strdup(path);
		if (!cfg->no)
			return (0);
	}
	else if (face == 4)
	{
		cfg->ea = ft_strdup(path);
		if (!cfg->no)
			return (0);
	}
	return (1);
}

int	check_texture(int face, char *path, t_config *cfg)
{
	int	fd;

	if (!check_extension(path, ".xpm"))
		return (0);
	fd = open(path, O_RDONLY);
	if (open(path, O_RDONLY) < 0)
		return (0);
	close(fd);
	return (dup_texture(face, path, cfg));
}

int	parse_parameters(t_config *cfg, char *line)
{
	char	**split;
	int		ret;

	ret = 1;
	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1] || split[2])
		return (free_split(split), 0);
	if (!ft_strncmp(split[0], "NO", 2))
		ret = check_texture(1, split[1], cfg);
	else if (!ft_strncmp(split[0], "SO", 2))
		ret = check_texture(2, split[1], cfg);
	else if (!ft_strncmp(split[0], "WE", 2))
		ret = check_texture(3, split[1], cfg);
	else if (!ft_strncmp(split[0], "EA", 2))
		ret = check_texture(4, split[1], cfg);
	else if (!ft_strncmp(split[0], "F", 1))
		cfg->floor_color = parse_color(split[1]);
	else if (!ft_strncmp(split[0], "C", 1))
		cfg->ceiling_color = parse_color(split[1]);
	else
		ret = 0;
	if (cfg->ceiling_color == -1 || cfg->floor_color == -1)
		ret = 0 ;
	return (free_split(split), ret);
}

int	parse_color(char *str)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	rgb = NULL;
	if (str)
		rgb = ft_split(str, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2])
		return (free_split(rgb), -1);
	if (!ft_isalldigit(rgb[0]) || !ft_isalldigit(rgb[1])
		|| !ft_isalldigit(rgb[2]))
		return (free_split(rgb), -1);
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_split(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return ((r << 16) | (g << 8) | b);
}

int	is_mapline(char *line)
{
	int	i;

	i = 0;
	if (ft_strcmp(line, "") == 0)
		return (ft_putstr_fd("Error\ninvalid map\n", 2), 1);
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\n')
		{
			ft_putstr_fd("Error\ninvalid character: ", 2);
			ft_putchar_fd(line[i], 2);
			ft_putstr_fd("\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
