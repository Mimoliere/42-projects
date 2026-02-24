/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:07:15 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/24 16:08:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

#define RESET   "\033[0m"
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */

int main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << BOLDMAGENTA << "\n--- Comparison operators ---" << RESET << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;

	std::cout << BOLDMAGENTA << "\n--- Arithmetic operators ---" << RESET << std::endl;
	Fixed c(10);
	Fixed d(3.5f);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "c + d = " << (c + d) << std::endl;
	std::cout << "c - d = " << (c - d) << std::endl;
	std::cout << "c * d = " << (c * d) << std::endl;
	std::cout << "c / d = " << (c / d) << std::endl;
	
	std::cout << BOLDMAGENTA << "\n--- Increment operators ---" << RESET << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << BOLDMAGENTA << "\n--- Decrement operators ---" << RESET << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;

	std::cout << BOLDMAGENTA << "\n--- Min/Max functions ---" << RESET << std::endl;
	std::cout << "min(c, d) = " << Fixed::min(c, d) << std::endl;
	std::cout << "max(c, d) = " << Fixed::max(c, d) << std::endl << std::endl;

	return (0);
}
