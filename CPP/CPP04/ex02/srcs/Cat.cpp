/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:37 by bguerrou          #+#    #+#             */
/*   Updated: 2026/03/12 17:18:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

Cat::Cat() {
	std::cout << GREEN << "Cat constructor called" << RESET << std::endl;

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
	std::cout << RED << "Cat destructor called" << RESET << std::endl;

	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << YELLOW << "🐱 Meooow" << RESET << std::endl;
}

Brain	Cat::getBrain() const {
	return (*_brain);
}

void	Cat::setBrain() {
	_brain = new Brain();
}
