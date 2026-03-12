/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:22 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:22 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

WrongAnimal::WrongAnimal() {
	std::cout << GREEN << "WrongAnimal constructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other.getType();
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED << "WrongAnimal destructor called" << RESET << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << MAGENTA << "❌ Hello euuuh.. Meow ?" << RESET << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void	WrongAnimal::setType(std::string const newType) {
	_type = newType;
}
