/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:29:59 by bguerrou          #+#    #+#             */
/*   Updated: 2025/10/30 15:01:48 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	argc_error(char *exe)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(exe, 2);
	ft_putstr_fd(" map.cub\n", 2);
}

int	check_extension(char *file, char *ex)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 4)
		return (0);
	return (ft_strncmp(file + len - 4, ex, 4) == 0);
}

char	**read_file(char *path)
{
	int		fd;
	char	*line;
	char	**lines;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * 10000);
	line = get_next_line(fd);
	while (line)
	{
		lines[i++] = ft_strtrim(line, "\n");
		free(line);
		line = get_next_line(fd);
	}
	lines[i] = NULL;
	close(fd);
	return (lines);
}

int	end(t_window *window)
{
	clear_exit(window, 0);
	return (0);
}
