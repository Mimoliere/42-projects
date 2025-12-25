/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:47:05 by bguerrou          #+#    #+#             */
/*   Updated: 2025/09/28 18:54:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	slen;

	slen = ft_strlen(s);
	if (s[slen] == (char) c)
		return ((char *) &s[slen]);
	while (slen-- > 0)
	{
		if (s[slen] == (char) c)
			return ((char *) &s[slen]);
	}
	return (0);
}
