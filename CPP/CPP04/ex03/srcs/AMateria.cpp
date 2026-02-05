/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:31 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/05 17:47:59 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::AMateria(const AMateria& other) {
	_type = other.getType();
}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

AMateria::~AMateria() {

}

std::string const &	AMateria::getType() const {
	return (_type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << "* does ??? to " << target.getName() << " *" << std::endl;
}
