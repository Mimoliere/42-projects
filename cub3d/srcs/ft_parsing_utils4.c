/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:54:53 by alo               #+#    #+#             */
/*   Updated: 2025/11/04 16:21:16 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	check_file(char *file, char ***lines)
{
	if (!check_extension(file, ".cub"))
	{
		ft_putstr_fd("Error\nfile must have .cub extension.\n", 2);
		return (0);
	}
	*lines = read_file(file);
	if (!*lines)
	{
		ft_putstr_fd("Error\ncouldn't read file.\n", 2);
		return (0);
	}
	return (1);
}

int	parameters(t_config *cfg, char **lines, int *i)
{
	int	first_lines;

	first_lines = 0;
	while (lines[*i] && first_lines < 6)
	{
		if (ft_strlen(lines[*i]) > 0)
		{
			if (!parse_parameters(cfg, lines[*i]))
			{
				ft_putstr_fd("Error\ninvalid parameter: ", 2);
				ft_putstr_fd(lines[*i], 2);
				return (ft_putstr_fd("\n", 2), 0);
			}
			first_lines++;
		}
		(*i)++;
	}
	if (first_lines < 6)
	{
		ft_putstr_fd("Error\nmissing parameters\n", 2);
		return (0);
	}
	return (1);
}

int	check_lines(char **lines, int i)
{
	int	s;

	while (ft_strcmp(lines[i], "") == 0)
		i++;
	while (lines[i])
	{
		s = is_mapline(lines[i]);
		if (s)
			return (0);
		i++;
	}
	return (1);
}

int	map(t_config *cfg, char **lines, int i)
{
	if (!parse_map(cfg, &lines[i]))
	{
		ft_putstr_fd("Error\ninvalid map\n", 2);
		return (0);
	}
	if (cfg->player_dir == 0)
	{
		ft_putstr_fd("Error\nno player found in map.\n", 2);
		return (0);
	}
	return (1);
}

int	check_tout(t_config *cfg, char *file)
{
	char	**lines;
	int		i;

	if (!check_file(file, &lines))
		return (0);
	i = 0;
	if (!parameters(cfg, lines, &i))
		return (free_split(lines), free_parsing(cfg), 0);
	if (!check_lines(lines, i))
		return (free_split(lines), free_parsing(cfg), 0);
	if (!map(cfg, lines, i))
		return (free_split(lines), free_parsing(cfg), 0);
	free_split(lines);
	return (1);
}
