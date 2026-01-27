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
