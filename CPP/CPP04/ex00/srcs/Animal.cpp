/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:11 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:11 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	_type = other.getType();
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal says Hello" << std::endl;
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::setType(std::string const newType) {
	_type = newType;
}
