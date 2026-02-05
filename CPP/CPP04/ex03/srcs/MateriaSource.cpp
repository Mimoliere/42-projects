/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:13:15 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/05 16:22:32 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	_nb_store = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	_nb_store = other.getNbStore();

	for (int i = 0; i < _nb_store; i++)
		_storage[i] = other._storage[i]->clone();
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _nb_store; i++)
			delete _storage[i];
	
		_nb_store = other.getNbStore();
		for (int i = 0; i < _nb_store; i++)
			_storage[i] = other._storage[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _nb_store; i++)
		delete _storage[i];
}

int	MateriaSource::getNbStore() const {
	return ((const int) _nb_store);
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (_nb_store == MAX_STORAGE) {
		std::cout << RED << "Can't store more Materias in this source." << RESET << std::endl;

		delete m;
		return ;
	}

	_storage[_nb_store++] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	AMateria*	ret;

	for (int i = 0; i < _nb_store; i++) {
		if (_storage[i]->getType().compare(type) == 0) {
			ret = _storage[i]->clone();
			return (ret);
		}
	}

	std::cout << RED << "No " << type << " materia stored." << RESET << std::endl;
	return (0);
}
