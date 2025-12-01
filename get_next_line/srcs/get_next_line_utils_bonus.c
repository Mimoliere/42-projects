/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:00:21 by bguerrou          #+#    #+#             */
/*   Updated: 2025/01/22 17:27:05 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	size_t			i;

	if (nmemb * size == 0)
		return (NULL);
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
		mem[i++] = 0;
	return (mem);
}

int	ft_has_char(char *str, char c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (1);
	return (0);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	int		j;
	char	*new;
	int		len;

	i = 0;
	while (s[i] && s[i] != (char) c)
		i++;
	len = ft_strlen(s) - i;
	new = malloc(sizeof(char) * len + 2);
	if (!new)
		return (NULL);
	j = 0;
	while (j < len)
		new[j++] = s[++i];
	new[j] = '\0';
	free(s);
	return (new);
}
