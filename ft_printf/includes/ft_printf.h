/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 16:22:20 by bguerrou          #+#    #+#             */
/*   Updated: 2025/11/30 22:43:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

void	ft_putchar_counts(char c, int *charcount);
void	ft_putstr_counts(char *s, int *charcount);
void	ft_putnbr_counts(int n, int *charcount);
void	ft_putnbrbase_counts(uintptr_t n, char *base, int *charcount, int iter);
int		ft_printf(const char *str, ...);

#endif
