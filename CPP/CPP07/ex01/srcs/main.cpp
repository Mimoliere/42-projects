/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:12:06 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/27 16:12:06 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <cstring>

int main(void) {
	std::cout << "--- Tableau de char ---" << std::endl;
	char str[] = "hello world";
	std::cout << "Original:      " << str << std::endl;

	std::cout << "Après toMaj:     ";
	::iter(str, std::strlen(str), toMaj);
	::iter(str, std::strlen(str), printIt<char>);
	std::cout << std::endl << std::endl;


	std::cout << "--- Tableau d'int ---" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Original:        ";
	::iter(intArray, 5, printIt<int>);
	std::cout << std::endl;

	::iter(intArray, 5, doubleIt);
	std::cout << "Après increment: ";
	::iter(intArray, 5, printIt<int>);
	std::cout << std::endl << std::endl;


	std::cout << "--- Tableau de chaînes const ---" << std::endl;
	const char* const constStrArray[] = {"One", "Two", "Three"};
	std::cout << "Contenu:         ";
	::iter(constStrArray, 3, printIt<const char*>);
	std::cout << std::endl;

	return (0);
}
