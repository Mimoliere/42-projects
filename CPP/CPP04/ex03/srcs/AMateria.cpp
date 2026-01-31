/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:31 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:31 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::AMateria(const AMateria& other) {

}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {

	}
	return (*this);
}

AMateria::~AMateria() {

}

std::string const &	AMateria::getType() const {
	return (_type);
}
