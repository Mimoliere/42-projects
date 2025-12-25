/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_functions1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:29:13 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 17:02:34 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_pilenew(int val)
{
	t_pile	*p;

	p = malloc(sizeof(t_pile));
	if (!p)
		return (NULL);
	p->val = val;
	p->next = NULL;
	return (p);
}

void	ft_pileclear(t_pile **pile)
{
	t_pile	*tmp;

	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
	*pile = NULL;
}

void	ft_pileadd_back(t_pile **pile, t_pile *new)
{
	t_pile	*p;

	p = *pile;
	if (p == NULL)
		ft_pileadd_front(pile, new);
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	ft_pileadd_front(t_pile **pile, t_pile *new)
{
	new->next = *pile;
	*pile = new;
}

int	ft_pilesize(t_pile *pile)
{
	t_pile	*p;
	int		count;

	p = pile;
	count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return (count);
}
