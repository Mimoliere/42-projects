/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:01:09 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/02 16:59:54 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_pile
{
	int				val;
	struct s_pile	*next;
}					t_pile;

t_pile	*init_pile(int argc, char **argv);
void	print_error(int code);
int		is_valid(char *str);
int		exist_in_pile(t_pile *pile, t_pile *new);
int		is_sorted(t_pile *pile);
int		is_reverse_sorted(t_pile *pile);
t_pile	*ft_pilenew(int val);
void	ft_pileclear(t_pile **pile);
void	ft_pileadd_back(t_pile **pile, t_pile *new);
void	ft_pileadd_front(t_pile **pile, t_pile *new);
int		ft_pilesize(t_pile *pile);
t_pile	*ft_pilelast(t_pile *pile);
int		get_max(t_pile *pile);
int		get_min(t_pile *pile);
int		ft_isin(t_pile *pile, int value);
int		ft_real_atoi(char **tab, int i, t_pile **pile, int argc);
void	swap(t_pile **pile, char name);
void	push(t_pile **a, t_pile **b, char name);
void	rotate(t_pile **pile, char name);
void	reverse_rotate(t_pile	**pile, char name);
void	swap_swap(t_pile **pile1, t_pile **pile2);
void	rotate_rotate(t_pile **pile1, t_pile **pile2);
void	reverse_reverse(t_pile **pile1, t_pile **pile2);
void	push_allin_a(t_pile **a, t_pile **b);
void	start_b(t_pile **a, t_pile **b);
void	sort3(t_pile **a);
void	sort_4_5(t_pile **a, t_pile **b);
char	assign_action(t_pile *pile, int value);
void	separately(t_pile **pile, char action, int count, int which);
void	bring_top(t_pile **a, int value_a, t_pile **b, int value_b);
int		optimal_a(t_pile *a, t_pile *b);
int		count_bring(t_pile *pile, int value);
int		nearest(t_pile *pile, int value);
int		nearest_high(t_pile *pile, int value);

#endif