/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedLists.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:21 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:21 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKEDLISTS_HPP
#define LINKEDLISTS_HPP

#include "Character.hpp"

struct t_abandoned {
	AMateria*		obj;
	t_abandoned*	next;
};

void	initList(t_abandoned*& head);
void	insertHead(t_abandoned*& head, AMateria*& newMateria);
void	insertBack(t_abandoned*& head, AMateria*& newMateria);
void	deleteNode(t_abandoned*& head, AMateria*& toDelete);
void	clearList(t_abandoned*& head);

#endif
