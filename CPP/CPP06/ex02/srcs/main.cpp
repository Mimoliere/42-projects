/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 15:45:41 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/23 17:04:37 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void) {
	srand(time(0));

	for (int i = 1; i <= 5; ++i) {
		std::cout << CYAN << "=== Test " << i << " ===" << RESET << std::endl;
		
		Base* randomBase = generate();
		
		std::cout << YELLOW << "[Pointer]   " << RESET;
		identify(randomBase);
		
		std::cout << GREEN << "[Reference] " << RESET;
		identify(*randomBase);
		
		delete randomBase;
		std::cout << std::endl;
	}

	return (0);
}

Base*	generate(void) {
	int		choice = rand() % 3;

	switch (choice) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}

	return (NULL);
}

void	identify(Base* p) {

	if (dynamic_cast<A*>(p))
		std::cout << "Type : A";
	else if (dynamic_cast<B*>(p))
		std::cout << "Type : B";
	else if (dynamic_cast<C*>(p))
		std::cout << "Type : C";
	else
		std::cout << "Type : Unknown.";

	std::cout << std::endl;
}

void	identify(Base& p) {

	try {
		(void) dynamic_cast<A&>(p);
		std::cout << "Type : A" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try {
		(void) dynamic_cast<B&>(p);
		std::cout << "Type : B" << std::endl;
		return ;
	} catch (std::exception& e) {}

	try {
		(void) dynamic_cast<C&>(p);
		std::cout << "Type : C" << std::endl;
		} catch (std::exception& e) {
			std::cout << "Type : Unknown." << std::endl;
	}
}
