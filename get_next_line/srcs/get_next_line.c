/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 13:04:36 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/01 01:30:03 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_next(int fd, char *cursor, char *buffer);
static char	*altered_ft_strjoin(char *s1, char const *s2);
static char	*ft_cut(char *src, char sep);

char	*get_next_line(int fd)
{
	char		*line;
	static char	*cursor = NULL;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(cursor);
		cursor = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(cursor), NULL);
	cursor = get_next(fd, cursor, buffer);
	free(buffer);
	if (!cursor)
		return (NULL);
	line = ft_cut(cursor, '\n');
	if (!line)
		return (free(cursor), NULL);
	cursor = ft_strchr(cursor, '\n');
	if (!cursor)
		return (free(line), NULL);
	return (line);
}

static char	*get_next(int fd, char *cursor, char *buffer)
{
	int			reader;

	reader = 1;
	if (!cursor)
		cursor = ft_calloc(1, sizeof(char));
	if (!cursor)
		return (NULL);
	while (!ft_has_char(cursor, '\n') && reader)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		buffer[reader] = '\0';
		cursor = altered_ft_strjoin(cursor, buffer);
		if (!cursor)
			return (NULL);
		if (reader == 0 && !ft_strlen(cursor))
			return (free(cursor), NULL);
	}
	return (cursor);
}

static char	*altered_ft_strjoin(char *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*join;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * len + 2);
	if (!join)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i])
		join[i] = (s1)[i];
	free(s1);
	j = 0;
	while (s2[j])
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

static char	*ft_cut(char *src, char sep)
{
	char	*str;
	int		char_pos;
	int		i;

	if (!src)
		return (NULL);
	char_pos = 0;
	while (src[char_pos] && src[char_pos] != sep)
		char_pos++;
	str = malloc(sizeof(char) * char_pos + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (++i <= char_pos)
		str[i] = src[i];
	str[i] = '\0';
	return (str);
}
