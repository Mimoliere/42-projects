/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:02:54 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 20:41:30 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_swap_bonus(t_pile **pile1, t_pile **pile2)
{
	swap_bonus(pile1);
	swap_bonus(pile2);
}

void	rotate_rotate_bonus(t_pile **pile1, t_pile **pile2)
{
	rotate_bonus(pile1);
	rotate_bonus(pile2);
}

void	reverse_reverse_bonus(t_pile **pile1, t_pile **pile2)
{
	reverse_rotate_bonus(pile1);
	reverse_rotate_bonus(pile2);
}
