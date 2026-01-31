/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:45 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:06:46 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor called" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	_rawBits = val << _fracBitsNb;
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(val * (1 << _fracBitsNb));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;	
	_rawBits = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		_rawBits = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	return (_rawBits);
}

void	Fixed::setRawBits(int const newRawBits) {
	_rawBits = newRawBits;
}

int		Fixed::toInt(void) const {
	return (_rawBits >> _fracBitsNb);
}

float	Fixed::toFloat(void) const {
	return ((float) _rawBits / (1 << _fracBitsNb));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
