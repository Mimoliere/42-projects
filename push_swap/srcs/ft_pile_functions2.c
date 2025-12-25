/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pile_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 18:53:30 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 17:03:57 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_pilelast(t_pile *pile)
{
	t_pile	*p;

	if (pile == NULL)
		return (NULL);
	p = pile;
	while (p->next)
		p = p->next;
	return (p);
}

int	get_max(t_pile *pile)
{
	t_pile	*p;
	int		max;

	if (!pile)
		return (0);
	max = pile->val;
	p = pile->next;
	while (p)
	{
		if (p->val > max)
			max = p->val;
		p = p->next;
	}
	return (max);
}

int	get_min(t_pile *pile)
{
	t_pile	*p;
	int		min;

	if (!pile)
		return (0);
	min = pile->val;
	p = pile->next;
	while (p)
	{
		if (p->val < min)
			min = p->val;
		p = p->next;
	}
	return (min);
}

int	ft_isin(t_pile *pile, int value)
{
	t_pile	*p;

	if (!pile)
		return (0);
	p = pile;
	while (p)
	{
		if (p->val == value)
			return (1);
		p = p->next;
	}
	return (0);
}

int	ft_real_atoi(char **tab, int i, t_pile **pile, int argc)
{
	unsigned char	*ptr;
	int				n;
	int				j;
	int				s;
	long long int	nb;

	ptr = (unsigned char *) *(tab + i);
	j = 0;
	nb = 0;
	s = 1;
	if (ptr[j] == '-')
	{
		s *= -1;
		j++;
	}
	else if (ptr[j] == '+')
		j++;
	while (ft_isdigit(ptr[j]))
		nb = 10 * nb + (ptr[j++] - '0');
	if ((nb * s > 2147483647 || nb * s < -2147483648) && argc == 2)
		return (ft_pileclear(pile), free_arr(tab), print_error(4), 0);
	else if (nb * s > 2147483647 || nb * s < -2147483648)
		return (ft_pileclear(pile), print_error(4), 0);
	n = nb;
	return (n * s);
}
