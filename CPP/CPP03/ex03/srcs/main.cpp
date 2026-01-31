/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:09:29 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:09:29 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include "../includes/FragTrap.hpp"
#include "../includes/DiamondTrap.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define BLUE    "\033[34m"
#define YELLOW  "\033[33m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"

int	main(void) {
	ClapTrap	clptrp("Pirouette");
	ScavTrap	scvtrp("Cacahuete");
	FragTrap	frgtrp("Petit homme");
	DiamondTrap	dmdtrp("Facteur");

	std::cout << std::endl << GREEN << "- So many clappers !" << RESET << std::endl;
	clptrp.attack("Macron");
	scvtrp.attack("Macron");
	frgtrp.attack("Macron");
	dmdtrp.attack("Macron");

	std::cout << std::endl << GREEN << "- Macron counter attacks !" << RESET << std::endl;
	clptrp.takeDamage(1);
	clptrp.beRepaired(1);
	scvtrp.takeDamage(1);
	scvtrp.beRepaired(1);
	frgtrp.takeDamage(1);
	frgtrp.beRepaired(1);
	dmdtrp.takeDamage(1);
	dmdtrp.beRepaired(1);
	std::cout << std::endl;

	std::cout << BLUE << "- ScavTrap special ability:" << RESET << std::endl;
	scvtrp.guardGate();
	std::cout << std::endl;

	std::cout << YELLOW << "- FragTrap special ability:" << RESET << std::endl;
	frgtrp.highFivesGuys();
	std::cout << std::endl;

	std::cout << MAGENTA << "- DiamondTrap special abilities:" << RESET << std::endl;
	dmdtrp.whoAmI();
	dmdtrp.guardGate();
	dmdtrp.highFivesGuys();
	std::cout << std::endl;

	std::cout << GREEN << "- Oh no, " << clptrp.getName() << " has iron deficiency !" << RESET << std::endl;
	std::cout << GREEN << "- And " << scvtrp.getName() << " too !?" << RESET << std::endl;
	std::cout << GREEN << "- And " << frgtrp.getName() << " as well !?" << RESET << std::endl;
	std::cout << GREEN << "- And " << dmdtrp.getName() << " is also affected !?" << RESET << std::endl;
	clptrp.setEp(0);
	scvtrp.setEp(0);
	frgtrp.setEp(0);
	dmdtrp.setEp(0);

	std::cout << std::endl << GREEN << "- They try to attack Adrien but..." << RESET << std::endl;
	clptrp.attack("Adrien");
	scvtrp.attack("Adrien");
	frgtrp.attack("Adrien");
	dmdtrp.attack("Adrien");

	std::cout << std::endl << GREEN << "- Even repairing themselves..." << RESET << std::endl;
	clptrp.beRepaired(1);
	scvtrp.beRepaired(1);
	frgtrp.beRepaired(1);
	dmdtrp.beRepaired(1);

	std::cout << std::endl;
	clptrp.takeDamage(11);
	scvtrp.takeDamage(100);
	frgtrp.takeDamage(100);
	dmdtrp.takeDamage(100);
	std::cout << GREEN << "- CLAPTRAP, SCAVTRAP, FRAGTRAP, DIAMONDTRAP NOOOOO" << RESET << std::endl;
	clptrp.takeDamage(1);
	scvtrp.takeDamage(1);
	frgtrp.takeDamage(1);
	dmdtrp.takeDamage(1);

	std::cout << std::endl;
	return (0);
}
