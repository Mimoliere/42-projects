/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:30 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 17:02:58 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_pile **pile, char name)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) <= 1)
		return ;
	tmp = (*pile)->next;
	(*pile)->next = tmp->next;
	tmp->next = *pile;
	*pile = tmp;
	if (name != 'r')
		ft_printf("s%c\n", name);
}

void	push(t_pile **a, t_pile **b, char name)
{
	t_pile	*tmp;

	if (ft_pilesize(*b) == 0)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (name != 'r')
		ft_printf("p%c\n", name);
}

void	rotate(t_pile **pile, char name)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) <= 1)
		return ;
	tmp = *pile;
	*pile = tmp->next;
	ft_pilelast(*pile)->next = tmp;
	tmp->next = NULL;
	if (name != 'r')
		ft_printf("r%c\n", name);
}

void	reverse_rotate(t_pile	**pile, char name)
{
	t_pile	*tmp;
	int		size;

	size = ft_pilesize(*pile);
	if (size <= 1)
		return ;
	tmp = *pile;
	*pile = ft_pilelast(*pile);
	(*pile)->next = tmp;
	tmp = *pile;
	while (tmp->next != *pile)
		tmp = tmp->next;
	tmp->next = NULL;
	if (name != 'r')
		ft_printf("rr%c\n", name);
}
