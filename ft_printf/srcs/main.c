/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 22:50:52 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/30 23:36:53 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	main(void)
{
	int	ft;
	int	res;

	ft = 42;
	res = ft_printf("Hello, this is the text to print for my %i project.\n", ft);
	ft_printf("(Wer printed %i characters above)\n", res);
}
