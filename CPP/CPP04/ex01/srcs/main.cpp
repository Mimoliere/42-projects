/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:06 by bguerrou          #+#    #+#             */
/*   Updated: 2026/03/12 17:21:26 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#define CYAN    "\033[36m"
#define BOLD    "\033[1m"
#define RESET   "\033[0m"

#define NBR 4

int main()
{
	Animal*	animals[NBR];
	Dog		dog;

	for (int i = 0; i < NBR; i++) {
		if (i < NBR / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}

	for (int i = 0; i < NBR; i++) {
		delete animals[i];
	}

	std::cout << std::endl;
	Dog	a;
	Dog	b = a;

	// b a son propre Brain, indépendant de celui de a → c'est une deep copy.
	std::cout << CYAN << BOLD << "These are deep copies." << RESET << std::endl << std::endl;

	return (0);
}
