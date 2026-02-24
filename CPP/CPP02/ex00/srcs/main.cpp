/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:33 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/11 13:00:46 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

int	main(void) {
	std::cout << "a : ";
	Fixed a;
	std::cout << "b : ";
	Fixed b(a);
	std::cout << "c : ";
	Fixed c;

	std::cout << std::endl << "c : ";
	c = b;
	std::cout << std::endl;

	std::cout << "a : " << a.getRawBits() << std::endl;
	std::cout << "b : " << b.getRawBits() << std::endl;
	std::cout << "c : " << c.getRawBits() << std::endl << std::endl;

	return (0);
}
