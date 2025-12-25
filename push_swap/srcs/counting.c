/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:27:40 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:11:12 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_both(t_pile *a, int value_a, t_pile *b, int value_b);

int	optimal_a(t_pile *a, t_pile *b)
{
	int		actions;
	int		min_actions;
	int		optimal;
	t_pile	*p;

	min_actions = count_bring(b, a->val) + 1;
	optimal = a->val;
	p = a->next;
	while (min_actions > 2 && p)
	{
		actions = count_both(a, p->val, b, nearest(b, p->val)) + 1;
		if (actions < min_actions)
		{
			min_actions = actions;
			optimal = p->val;
		}
		p = p->next;
	}
	return (optimal);
}

static int	count_both(t_pile *a, int value_a, t_pile *b, int value_b)
{
	char	action_a;
	char	action_b;
	int		count_a;
	int		count_b;
	int		count;

	action_a = assign_action(a, value_a);
	action_b = assign_action(b, value_b);
	count_a = count_bring(a, value_a);
	count_b = count_bring(b, value_b);
	if ((action_a == 'r' && action_b == 'r')
		|| (action_a == 'i' && action_b == 'i'))
		count = ft_max(count_a, count_b);
	else
		count = count_a + count_b;
	return (count);
}

int	count_bring(t_pile *pile, int value)
{
	t_pile	*p;
	int		counter;
	int		to_bring;

	if (!pile)
		return (0);
	p = pile;
	counter = 0;
	if (value > get_max(pile) || value < get_min(pile))
		to_bring = get_max(pile);
	else if (ft_isin(pile, value))
		to_bring = value;
	else
		to_bring = nearest(pile, value);
	while (p->val != to_bring)
	{
		counter++;
		p = p->next;
	}
	if (counter <= ft_pilesize(pile) - counter)
		return (counter);
	else
		return (ft_pilesize(pile) - counter);
}

int	nearest(t_pile *pile, int value)
{
	t_pile	*p;
	int		nearest;

	if (!pile)
		return (0);
	nearest = pile->val;
	p = pile->next;
	while (p)
	{
		if (p->val < value && (p->val > nearest || nearest > value))
			nearest = p->val;
		if (value - nearest == 1 || (value == 0 && value - nearest == -1))
			return (nearest);
		p = p->next;
	}
	return (nearest);
}

int	nearest_high(t_pile *pile, int value)
{
	t_pile	*p;
	int		nearest;

	if (!pile)
		return (0);
	nearest = pile->val;
	p = pile->next;
	while (p)
	{
		if (p->val > value && (p->val < nearest || nearest < value))
			nearest = p->val;
		if (nearest - value == 1)
			return (nearest);
		p = p->next;
	}
	if (nearest < value)
		nearest = get_min(pile);
	return (nearest);
}
