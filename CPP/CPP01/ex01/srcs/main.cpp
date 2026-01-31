/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:04:40 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:04:41 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int	main(void) {
	Zombie*	horde;
	int		N = 5;

	std::cout << "Oh wow ! A horde of Freeze Corleone !" << std::endl;
	horde = zombieHorde(N, "Freeze Corleone");

	std::cout << std::endl << "What's the first one saying ?" << std::endl;
	horde->announce();

	std::cout << std::endl << "Oh okay. And all the others ?" << std::endl;
	for (int i = 1; i < N; i++) {
		horde[i].announce();
	}

	std::cout << std::endl << "I see... Just get destroyed already." << std::endl;
	delete[] horde;
	std::cout << std::endl;

	return (0);
}
