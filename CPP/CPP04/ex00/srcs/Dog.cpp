/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:16 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:16 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;

	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
	_type = other.getType();
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}
