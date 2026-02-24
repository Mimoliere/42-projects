/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:48 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/24 15:13:50 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int main( void ) {
	std::cout << "a: ";
	Fixed		a;
	std::cout << "b: ";
	Fixed const	b( 10 );
	std::cout << "c: ";
	Fixed const	c( 42.42f );
	std::cout << "d: ";
	Fixed const	d( b );
	std::cout << std::endl;

	std::cout << "a: ";
	a = Fixed( 1234.4321f );
	std::cout << std::endl;

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "a is " << a.toFloat() << " as floating" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toFloat() << " as floating" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl << std::endl;

	/* Avec 8 bits fractionnaires, la plus petite valeur représentable est 1/256 = 0.00390625. On ne peux représenter que des multiples de cette valeur */

	return (0);
}