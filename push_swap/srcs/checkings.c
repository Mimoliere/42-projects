/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:22:16 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:12:11 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_error(int code)
{
	ft_putstr_fd("Error\n", 2);
	exit(code);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) > 1)
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	exist_in_pile(t_pile *pile, t_pile *new)
{
	t_pile	*p;

	p = pile;
	while (p)
	{
		if (p->val == new->val)
			return (1);
		p = p->next;
	}
	return (0);
}

int	is_sorted(t_pile *pile)
{
	t_pile	*p;
	t_pile	*t;

	if (!pile || pile->next == NULL)
		return (1);
	p = pile;
	while (p)
	{
		t = p->next;
		while (t)
		{
			if (p->val > t->val)
				return (0);
			t = t->next;
		}
		p = p->next;
	}
	return (1);
}

int	is_reverse_sorted(t_pile *pile)
{
	t_pile	*p;
	t_pile	*t;

	if (!pile || pile->next == NULL)
		return (1);
	p = pile;
	while (p)
	{
		t = p->next;
		while (t)
		{
			if (p->val < t->val)
				return (0);
			t = t->next;
		}
		p = p->next;
	}
	return (1);
}
