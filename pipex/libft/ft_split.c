/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:01:38 by bguerrou          #+#    #+#             */
/*   Updated: 2025/02/23 17:46:12 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;
	int	words;

	count = 1;
	i = 0;
	words = 0;
	while (s[i])
	{
		if (count == 1 && s[i] != c)
		{
			words++;
			count = 0;
		}
		else if (count == 0 && s[i] == c)
			count = 1;
		i++;
	}
	return (words);
}

char	*ft_cpytillsep(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_alloc(char const *s, char c, char **split)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			split[j] = ft_cpytillsep(s + i, c);
			if (!split)
			{
				while (j >= 0)
					free(split[j--]);
				return (free(split), NULL);
			}
			j++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!split)
		return (NULL);
	split = ft_alloc(s, c, split);
	if (!split)
		return (NULL);
	return (split);
}
