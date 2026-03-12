/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:55 by bguerrou          #+#    #+#             */
/*   Updated: 2026/03/12 17:18:07 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

Animal::Animal() {
	std::cout << GREEN << "Animal constructor called" << RESET << std::endl;
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
	std::cout << RED << "Animal destructor called" << RESET << std::endl;
}

void	Animal::makeSound() const {
	std::cout << YELLOW << "Animal says Hello" << RESET << std::endl;
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::setType(std::string const newType) {
	_type = newType;
}
