/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:13:03 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:13:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"

Ice::Ice() : AMateria("ice") {
}

Ice::Ice(const Ice& other) : AMateria(other) {

}

Ice&	Ice::operator=(const Ice& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return (*this);
}

Ice::~Ice() {

}

AMateria*	Ice::clone() const {
	Ice*	newIce = new Ice();

	return (newIce);
}

void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
