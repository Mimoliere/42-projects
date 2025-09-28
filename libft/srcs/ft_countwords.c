/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:01:59 by bguerrou          #+#    #+#             */
/*   Updated: 2025/09/28 18:54:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_countwords(char const *s, char c)
{
	int	count;
	int	i;
	int	words;

	if (!s)
		return (0);
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
