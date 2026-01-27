#include "../includes/linkedLists.hpp"

void	initList(t_abandoned*& head) {
	head = NULL;
}

void	insertHead(t_abandoned*& head, AMateria*& newMateria) {
	t_abandoned*	newNode = new t_abandoned;

	newNode->obj = newMateria;
	newNode->next = head;
	head = newNode;
}

void	insertBack(t_abandoned*& head, AMateria*& newMateria) {
	t_abandoned*	newNode = new t_abandoned;
	t_abandoned*	curr;

	newNode->obj = newMateria;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return ;
	}

	curr = head;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	curr->next = newNode;
}

void	deleteNode(t_abandoned*& head, AMateria*& toDelete) {
	t_abandoned*	curr;
	t_abandoned*	tmp;

	if (head == NULL)
		return ;

	if (head->obj == toDelete) {
		tmp = head;
		head = head->next;
		delete tmp;
		return ;
	}

	curr = head;
	while (curr->next != NULL && curr->next->obj != toDelete) {
		curr = curr->next;
	}

	if (curr->next != NULL) {
		tmp = curr->next;
		curr->next = curr->next->next;
		delete tmp;
	}
}

void	clearList(t_abandoned*& head) {
	if (head == NULL)
		return ;

	if (head->next)
		clearList(head->next);
	delete head->obj;
	delete head;
}
