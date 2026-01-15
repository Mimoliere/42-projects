/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alo <alo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:19:22 by bguerrou          #+#    #+#             */
/*   Updated: 2025/09/04 22:51:46 by alo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dtmp;
	unsigned char	*stmp;
	size_t			i;

	if (!dest && !src)
		return (dest);
	dtmp = (unsigned char *) dest;
	stmp = (unsigned char *) src;
	i = 0;
	if (dtmp > stmp)
	{
		while (n-- > 0)
			dtmp[n] = stmp[n];
	}
	else
	{
		while (i < n)
		{
			dtmp[i] = stmp[i];
			i++;
		}
	}
	return (dest);
}
