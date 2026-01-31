/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:10:25 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:10:25 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;

	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {

	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
