/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:34:34 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 23:10:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_pile	*one_arg(char *arg, int argc);

t_pile	*init_pile(int argc, char **argv)
{
	t_pile	*pile;
	t_pile	*p;
	int		i;

	if (argc == 2)
		return (one_arg(argv[1], argc));
	p = NULL;
	pile = NULL;
	i = 1;
	while (*(argv + i))
	{
		if (!is_valid(*(argv + i)))
			return (ft_pileclear(&pile), print_error(3), NULL);
		p = ft_pilenew(ft_real_atoi(argv, i, &pile, argc));
		if (!p)
			return (ft_pileclear(&pile), NULL);
		if (exist_in_pile(pile, p))
			return (ft_pileclear(&pile), ft_pileclear(&p),
				print_error(5), NULL);
		ft_pileadd_back(&pile, p);
		i++;
	}
	return (pile);
}

static t_pile	*one_arg(char *arg, int argc)
{
	t_pile	*pile;
	t_pile	*p;
	char	**tab;
	int		i;

	tab = ft_split(arg, ' ');
	if (!tab)
		print_error(4);
	pile = NULL;
	p = NULL;
	i = 0;
	while (*(tab + i))
	{
		if (!is_valid(*(tab + i)))
			return (free_arr(tab), ft_pileclear(&pile), print_error(3), NULL);
		p = ft_pilenew(ft_real_atoi(tab, i, &pile, argc));
		if (!p)
			return (ft_pileclear(&pile), free_arr(tab), NULL);
		if (exist_in_pile(pile, p))
			return (ft_pileclear(&pile), ft_pileclear(&p),
				free_arr(tab), print_error(5), NULL);
		ft_pileadd_back(&pile, p);
		i++;
	}
	return (free_arr(tab), pile);
}
