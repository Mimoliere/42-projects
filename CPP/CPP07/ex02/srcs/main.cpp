/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:53:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/05/16 13:30:24 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void) {
	// Constructeur vide
	Array<int>	empty;
	std::cout << "empty size: " << empty.size() << std::endl;

	// Constructeur avec n
	Array<int>	a(5);
	std::cout << "a size: " << a.size() << std::endl;
	for (unsigned int i = 0; i < a.size(); i++) {
		a[i] = i * 10;
		std::cout << "a[" << i << "] = " << a[i] << std::endl;
	}
	
	// Copie profonde
	Array<int>	b(a);
	b[0] = 999;
	std::cout << "a[0] apres modif de b: " << a[0] << std::endl;
	std::cout << "b[0]: " << b[0] << std::endl;

	// Out of bounds
	try {
		std::cout << a[99] << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
