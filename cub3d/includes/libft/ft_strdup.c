/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:34:10 by bguerrou          #+#    #+#             */
/*   Updated: 2025/10/29 16:23:12 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s)
{
	size_t		slen;
	char		*dup;
	size_t		i;

	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * slen + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ghetto_strdup(const char *s)
{
	size_t		slen;
	char		*dup;
	size_t		i;

	slen = ft_strlen(s);
	dup = malloc(sizeof(char) * slen + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < slen)
		dup[i++] = '0';
	dup[i] = '\0';
	return (dup);
}
