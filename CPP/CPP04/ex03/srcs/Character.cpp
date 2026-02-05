/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:34 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/05 16:25:25 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

Character::Character(const std::string& name) {
	_name = name;
	for (int i = 0; i < MAX_INVENTORY; i++) {
		_inventory[i] = NULL;
	}
	initList(_abandon);
}

Character::Character(const Character& other) {
	_name = other.getName();
	initList(_abandon);

	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (other._inventory[i] != NULL)
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other.getName();

		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
		}
		
		for (int i = 0; i < MAX_INVENTORY; i++) {
			if (other._inventory[i] != NULL)
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
		
		clearList(_abandon);
		initList(_abandon);
	}
	return (*this);
}

Character::~Character() {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}

	clearList(_abandon);
}

std::string const &	Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < MAX_INVENTORY; i++) {
		if (_inventory[i] == NULL && m != NULL) {
			_inventory[i] = m;
			std::cout << m->getType() << " equiped at index : " << i + 1 << " !" << std::endl;
			return ;
		}
		else if (_inventory[i] == NULL) {
			return ;
		}
	}

	std::cout << RED << "Inventory is full !" << RESET << std::endl;
	delete m;
	m = NULL;
	return ;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > MAX_INVENTORY - 1) {
		std::cout << RED << "Wrong index !" << RESET << std::endl;
		return ;
	}

	if (_inventory[idx] != NULL) {
		AMateria*	clone = _inventory[idx]->clone();
		insertBack(_abandon, clone);
		delete _inventory[idx];
		_inventory[idx] = NULL;
		std::cout << clone->getType() << " unequiped at index : " << idx + 1 << std::endl;
	}
	else {
		std::cout << RED << "No weapon here !" << RESET << std::endl;
	}
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > MAX_INVENTORY - 1) {
		std::cout << RED << "Wrong index !" << RESET << std::endl;
		return ;
	}

	if (_inventory[idx] != NULL)
		_inventory[idx]->use(target);
	else {
		std::cout << RED << "No weapon here !" << RESET << std::endl;
	}
}
