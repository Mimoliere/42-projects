/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi2020@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:27:14 by bguerrou          #+#    #+#             */
/*   Updated: 2024/11/18 17:44:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*mem;
	int				i;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	i = 0;
	while (mem[i])
		mem[i++] = 0;
	return (mem);
}
