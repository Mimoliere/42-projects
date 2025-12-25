/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:22:30 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 20:41:27 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_bonus(t_pile **pile)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) <= 1)
		return ;
	tmp = (*pile)->next;
	(*pile)->next = tmp->next;
	tmp->next = *pile;
	*pile = tmp;
}

void	push_bonus(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (ft_pilesize(*b) == 0)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
}

void	rotate_bonus(t_pile **pile)
{
	t_pile	*tmp;

	if (ft_pilesize(*pile) <= 1)
		return ;
	tmp = *pile;
	*pile = tmp->next;
	ft_pilelast(*pile)->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate_bonus(t_pile	**pile)
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
}
