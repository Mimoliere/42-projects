/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:08:21 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:08:22 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main(void) {
	ClapTrap	clptrp("Pirouette");
	ScavTrap	scvtrp("Cacahuete");

	std::cout << std::endl << GREEN << "- So many clappers !" << RESET << std::endl;
	clptrp.attack("Macron");
	scvtrp.attack("Macron");

	std::cout << std::endl << GREEN << "- Macron counter attacks !" << RESET << std::endl;
	clptrp.takeDamage(1);
	clptrp.beRepaired(1);
	scvtrp.takeDamage(1);
	scvtrp.beRepaired(1);
	std::cout << std::endl;

	std::cout << GREEN << "- Oh no, " << clptrp.getName() << " has iron deficiency !" << RESET << std::endl;
	std::cout << GREEN << "- And " << scvtrp.getName() << " too !?" << RESET << std::endl; 
	clptrp.setEp(0);
	scvtrp.setEp(0);

	std::cout << std::endl << GREEN << "- They try to attack Adrien but..." << RESET << std::endl;
	clptrp.attack("Adrien");
	scvtrp.attack("Adrien");

	std::cout << std::endl << GREEN << "- Even repairing thenselves..." << RESET << std::endl;
	clptrp.beRepaired(1);
	scvtrp.beRepaired(1);

	std::cout << std::endl;
	clptrp.takeDamage(11);
	scvtrp.takeDamage(100);
	std::cout << GREEN << "- CLAPTRAP, SCAVTRAP NOOOOO" << RESET << std::endl;
	clptrp.takeDamage(1);
	scvtrp.takeDamage(1);

	return (0);
}
