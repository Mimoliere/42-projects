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

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

Dog::Dog() {
	std::cout << GREEN << "Dog constructor called" << RESET << std::endl;

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
	std::cout << RED << "Dog destructor called" << RESET << std::endl;
}

void	Dog::makeSound() const {
	std::cout << YELLOW << "🐶 Woof woof" << RESET << std::endl;
}
