/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:00:06 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:00:40 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort(t_pile **a, t_pile **b);

int	main(int argc, char *argv[])
{
	t_pile	*pile;
	t_pile	*second;

	second = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2 && ft_strncmp(argv[1], "", ft_strlen(argv[1])) == 0)
		print_error(1);
	pile = init_pile(argc, argv);
	if (!pile)
		return (-1);
	if (is_sorted(pile))
		return (ft_pileclear(&pile), 1);
	if (ft_pilesize(pile) <= 5)
		sort_4_5(&pile, &second);
	else
		sort(&pile, &second);
	ft_pileclear(&pile);
	return (0);
}

static void	sort(t_pile **a, t_pile **b)
{
	int	max_b;
	int	min_b;
	int	actual_a;

	if (!ft_pilesize(*b))
		start_b(a, b);
	while (ft_pilesize(*a) > 5)
	{
		max_b = get_max(*b);
		min_b = get_min(*b);
		actual_a = optimal_a(*a, *b);
		if (actual_a > max_b || actual_a < min_b)
			bring_top(a, actual_a, b, max_b);
		else
			bring_top(a, actual_a, b, nearest(*b, actual_a));
		push(b, a, 'b');
	}
	if (ft_pilesize(*a) <= 5)
		sort_4_5(a, b);
	if (ft_pilesize(*b) > 0)
		push_allin_a(a, b);
}
