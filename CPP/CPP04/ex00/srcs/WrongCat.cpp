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

#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"
#define RESET   "\033[0m"

WrongCat::WrongCat() {
	std::cout << GREEN << "WrongCat constructor called" << RESET << std::endl;

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
	std::cout << MAGENTA << "❌ Meow meow" << RESET << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << RED << "WrongCat destructor called" << RESET << std::endl;
}
