/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:46 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 20:53:36 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	conditions(t_pile **a, t_pile **b, char *ins, int len);
int	reading(t_pile **a);

int	main(int argc, char **argv)
{
	t_pile	*pile;
	int		result;

	if (argc < 2)
		return (1);
	if (argc == 2 && ft_strncmp(argv[1], "", ft_strlen(argv[1])) == 0)
		print_error(1);
	pile = init_pile(argc, argv);
	if (!pile)
		print_error(2);
	if (is_sorted(pile))
		return (ft_putstr_fd("OK\n", 1), ft_pileclear(&pile), 0);
	result = reading(&pile);
	if (result == -1)
		return (ft_pileclear(&pile), -1);
	else if (result == 2)
		return (print_error(5), 5);
	else if (!result)
		return (ft_putstr_fd("KO\n", 1), 6);
	ft_putstr_fd("OK\n", 1);
	return (0);
}

int	conditions(t_pile **a, t_pile **b, char *ins, int len)
{
	if (ft_strncmp(ins, "sa\n", len) == 0)
		swap_bonus(a);
	else if (ft_strncmp(ins, "sb\n", len) == 0)
		swap_bonus(b);
	else if (ft_strncmp(ins, "pa\n", len) == 0)
		push_bonus(a, b);
	else if (ft_strncmp(ins, "pb\n", len) == 0)
		push_bonus(b, a);
	else if (ft_strncmp(ins, "ra\n", len) == 0)
		rotate_bonus(a);
	else if (ft_strncmp(ins, "rb\n", len) == 0)
		rotate_bonus(b);
	else if (ft_strncmp(ins, "rra\n", len) == 0)
		reverse_rotate_bonus(a);
	else if (ft_strncmp(ins, "rrb\n", len) == 0)
		reverse_rotate_bonus(b);
	else if (ft_strncmp(ins, "ss\n", len) == 0)
		swap_swap_bonus(a, b);
	else if (ft_strncmp(ins, "rr\n", len) == 0)
		rotate_rotate_bonus(a, b);
	else if (ft_strncmp(ins, "rrr\n", len) == 0)
		reverse_reverse_bonus(a, b);
	else
		return (2);
	return (1);
}

int	reading(t_pile **a)
{
	char	*line;
	t_pile	*b;

	b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (conditions(a, &b, line, ft_strlen(line)) == 2)
			return (free(line), ft_pileclear(&b), ft_pileclear(a), 2);
		free(line);
	}
	free(line);
	if (is_sorted(*a) && ft_pilesize(b) == 0)
		return (ft_pileclear(a), 1);
	return (ft_pileclear(a), ft_pileclear(&b), 0);
}
