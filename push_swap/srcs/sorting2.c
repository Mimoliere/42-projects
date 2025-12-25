/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:11:20 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:03:20 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	five_four(t_pile **a, t_pile **b);
void	sort3(t_pile **a);

void	sort_4_5(t_pile **a, t_pile **b)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = ft_pilesize(*a);
	if (size > 3)
		five_four(a, b);
	if (size > 4 && !is_sorted(*a))
		five_four(a, b);
	sort3(a);
	push_allin_a(a, b);
}

void	five_four(t_pile **a, t_pile **b)
{
	int		min_a;
	t_pile	*p;
	int		size;
	int		count;

	min_a = get_min(*a);
	p = *a;
	size = ft_pilesize(*a);
	count = 0;
	while (p->val != min_a)
	{
		count++;
		p = p->next;
	}
	if (count == 1)
		swap(a, 'a');
	else if (count <= size - count)
		separately(a, 'r', count, 0);
	else
		separately(a, 'i', size - count, 0);
	if (is_sorted(*a))
		return ;
	push(b, a, 'b');
}

void	sort3(t_pile **a)
{
	if (ft_pilesize(*a) == 2 && !is_sorted(*a))
		return (swap(a, 'a'));
	while (!is_sorted(*a))
	{
		if (((*a)->val < (*a)->next->val
				&& (*a)->next->val > (*a)->next->next->val
				&& (*a)->val < (*a)->next->next->val)
			|| ((*a)->next->val < (*a)->next->next->val
				&& (*a)->val < (*a)->next->next->val
				&& (*a)->val > (*a)->next->val)
			|| ((*a)->next->next->val < (*a)->val && (*a)->next->val < (*a)->val
				&& (*a)->next->val > (*a)->next->next->val))
			swap(a, 'a');
		if ((*a)->next->val < (*a)->val && (*a)->next->next->val < (*a)->val
			&& (*a)->next->next->val > (*a)->next->val)
			rotate(a, 'a');
		else if ((*a)->next->next->val < (*a)->next->val
			&& (*a)->val < (*a)->next->val
			&& (*a)->val > (*a)->next->next->val)
			reverse_rotate(a, 'a');
	}
}
