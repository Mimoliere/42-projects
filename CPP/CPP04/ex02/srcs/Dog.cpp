/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:40 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;

	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
	_type = other.getType();
	_brain = new Brain(*other._brain);
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other.getType();
		_brain = new Brain(*other._brain);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;

	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

Brain	Dog::getBrain() const {
	return (*_brain);
}

void	Dog::setBrain() {
	_brain = new Brain();
}
