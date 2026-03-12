/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:40 by bguerrou          #+#    #+#             */
/*   Updated: 2026/03/12 17:18:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

Dog::Dog() {
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;

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
	std::cout << RED << "Dog destructor called" << RESET << std::endl;

	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << YELLOW << "🐶 Woof woof" << RESET << std::endl;
}

Brain	Dog::getBrain() const {
	return (*_brain);
}

void	Dog::setBrain() {
	_brain = new Brain();
}
