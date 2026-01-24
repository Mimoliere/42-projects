#include "../includes/ClapTrap.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

int	main(void) {
	ClapTrap	clptrp("Pirouette");

	std::cout << std::endl << GREEN << "- Go ClapTrap !" << RESET << std::endl;
	clptrp.attack("Macron");
	std::cout << GREEN << "- Macron counter attacks !" << RESET << std::endl;
	clptrp.takeDamage(1);
	clptrp.beRepaired(1);
	std::cout << std::endl;

	std::cout << GREEN << "- Oh no, " << clptrp.getName() << " has iron deficiency !" << RESET << std::endl; 
	clptrp.setEp(0);

	std::cout << std::endl << GREEN << "- He tries to attack Adrien but..." << RESET << std::endl;
	clptrp.attack("Adrien");
	std::cout << GREEN << "- Even repairing himself..." << RESET << std::endl;
	clptrp.beRepaired(1);

	clptrp.takeDamage(11);
	std::cout << GREEN << "- CLAPTRAP NOOOOO" << RESET << std::endl;
	clptrp.takeDamage(1);
}
