/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 23:12:24 by alo               #+#    #+#             */
/*   Updated: 2025/11/04 15:27:19 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

char	*ft_strnjoin(char *s1, char *s2, int size)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	i = ft_strlen(s1);
	res = malloc(sizeof(char) * (i + size + 1));
	if (!res)
		return (0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] && j < size)
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = 0;
	return (res);
}

void	free_split(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_n(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*get_next_line2(char *line, int fd)
{
	static char	buffer[2];
	char		*res;
	int			size;

	if (!buffer[0])
	{
		if (read(fd, buffer, 2) == -1 || !buffer[0])
			return (NULL);
	}
	size = check_n(buffer);
	res = ft_strnjoin(line, buffer, size);
	if (!res)
		return (NULL);
	if (line)
		free(line);
	ft_shiftmem(buffer, size, 2);
	return (res);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*cpy;

	line = NULL;
	line = get_next_line2(line, fd);
	while (line && line[ft_strlen(line) - 1] != '\n')
	{
		cpy = line;
		line = get_next_line2(line, fd);
		if (!line)
			return (cpy);
	}
	return (line);
}
