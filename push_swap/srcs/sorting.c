/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:44:06 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 17:02:53 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	assign_action(t_pile *pile, int value)
{
	char	action;
	int		count;
	t_pile	*p;

	count = 0;
	p = pile;
	while (p && p->val != value)
	{
		count++;
		p = p->next;
	}
	if (count <= ft_pilesize(pile) - count)
		action = 'r';
	else
		action = 'i';
	return (action);
}

void	separately(t_pile **pile, char action, int count, int which)
{
	if (which == 0)
	{
		while (count-- > 0)
		{
			if (action == 'r')
				rotate(pile, 'a');
			else
				reverse_rotate(pile, 'a');
		}
	}
	else
	{
		while (count-- > 0)
		{
			if (action == 'r')
				rotate(pile, 'b');
			else
				reverse_rotate(pile, 'b');
		}
	}
}

static void	same_time(t_pile **a, int value_a, t_pile **b, int value_b)
{
	char	action_a;
	char	action_b;
	int		count_a;
	int		count_b;

	action_a = assign_action(*a, value_a);
	action_b = assign_action(*b, value_b);
	count_a = count_bring(*a, value_a);
	count_b = count_bring(*b, value_b);
	if (action_a == 'r' && action_b == 'r')
	{
		while (count_a-- > 0 && count_b-- > 0)
			rotate_rotate(a, b);
	}
	else if (action_a == 'i' && action_b == 'i')
	{
		while (count_a-- > 0 && count_b-- > 0)
			reverse_reverse(a, b);
	}
}

void	bring_top(t_pile **a, int value_a, t_pile **b, int value_b)
{
	int		count_a;
	int		count_b;
	char	action_a;
	char	action_b;

	if (!*a)
		return ;
	same_time(a, value_a, b, value_b);
	action_a = assign_action(*a, value_a);
	action_b = assign_action(*b, value_b);
	count_a = count_bring(*a, value_a);
	count_b = count_bring(*b, value_b);
	separately(a, action_a, count_a, 0);
	separately(b, action_b, count_b, 1);
}
