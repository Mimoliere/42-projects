/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 18:00:00 by bguerrou          #+#    #+#             */
/*   Updated: 2025/12/25 20:41:01 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../../includes/push_swap.h"

void	swap_bonus(t_pile **pile);
void	push_bonus(t_pile **a, t_pile **b);
void	rotate_bonus(t_pile **pile);
void	reverse_rotate_bonus(t_pile	**pile);
void	swap_swap_bonus(t_pile **pile1, t_pile **pile2);
void	rotate_rotate_bonus(t_pile **pile1, t_pile **pile2);
void	reverse_reverse_bonus(t_pile **pile1, t_pile **pile2);

#endif
