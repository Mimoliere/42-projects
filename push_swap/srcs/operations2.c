/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:02:54 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 17:02:53 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_swap(t_pile **pile1, t_pile **pile2)
{
	swap(pile1, 'r');
	swap(pile2, 'r');
	ft_printf("ss\n");
}

void	rotate_rotate(t_pile **pile1, t_pile **pile2)
{
	rotate(pile1, 'r');
	rotate(pile2, 'r');
	ft_printf("rr\n");
}

void	reverse_reverse(t_pile **pile1, t_pile **pile2)
{
	reverse_rotate(pile1, 'r');
	reverse_rotate(pile2, 'r');
	ft_printf("rrr\n");
}

void	push_allin_a(t_pile **a, t_pile **b)
{
	int	bsize;
	int	nearest;

	bsize = ft_pilesize(*b);
	while (bsize--)
	{
		nearest = nearest_high(*a, (*b)->val);
		bring_top(a, nearest, b, (*b)->val);
		push(a, b, 'a');
	}
	bring_top(a, get_min(*a), b, 0);
	ft_pileclear(a);
	exit(0);
}

void	start_b(t_pile **a, t_pile **b)
{
	push(b, a, 'b');
	if (ft_pilesize(*a) == 5)
		return ;
	push(b, a, 'b');
}
