/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:37 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:38 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;

	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
	_type = other.getType();
	_brain = new Brain(*other._brain);
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other.getType();
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;

	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << "Meooow" << std::endl;
}

Brain	Cat::getBrain() const {
	return (*_brain);
}

void	Cat::setBrain() {
	_brain = new Brain();
}
