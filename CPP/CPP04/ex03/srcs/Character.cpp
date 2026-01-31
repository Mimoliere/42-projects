/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:34 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:34 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(const std::string& name) {
	_name = name;
	_nb_equip = 0;
	initList(_abandon);
}

Character::Character(const Character& other) {
	_name = other.getName();
	_nb_equip = other.getNbEquip();
	initList(_abandon);

	for (int i = 0; i < _nb_equip; i++)
		_inventory[i] = other._inventory[i]->clone();
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other.getName();

		for (int i = 0; i < _nb_equip; i++)
			delete _inventory[i];
		
		_nb_equip = other.getNbEquip();
		for (int i = 0; i < _nb_equip; i++)
			_inventory[i] = other._inventory[i]->clone();
		
		clearList(_abandon);
		initList(_abandon);
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < _nb_equip; i++)
		delete _inventory[i];

	clearList(_abandon);
}

std::string const &	Character::getName() const {
	return (_name);
}

int	const	Character::getNbEquip() const {
	return (_nb_equip);
}

void	Character::equip(AMateria* m) {
	if (_nb_equip == MAX_INVENTORY) {
		std::cout << "Inventory is full !" << std::endl;
		return ;
	}

	_inventory[_nb_equip++] = m;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > _nb_equip - 1)
		return ;

	insertBack(_abandon, _inventory[idx]);
	_inventory[idx] = NULL;
	_nb_equip--;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > _nb_equip - 1)
		return ;

	_inventory[idx]->use(target);
}
