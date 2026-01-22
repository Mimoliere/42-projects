/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:33 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/22 14:44:35 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philo_error(char *str, int code)
{
	write(2, str, ft_strlen(str));
	return (code);
}
