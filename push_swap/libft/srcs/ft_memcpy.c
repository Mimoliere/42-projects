/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:56:27 by bguerrou          #+#    #+#             */
/*   Updated: 2025/09/28 18:54:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;
	size_t			i;

	if (!dest && !src)
		return (dest);
	dtmp = (unsigned char *) dest;
	stmp = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dtmp[i] = stmp[i];
		i++;
	}
	return (dest);
}
