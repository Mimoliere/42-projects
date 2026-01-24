#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap default constructor called" << std::endl;

	_hp = 100;
	_ep = 100;
	_ad = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {

}

FragTrap&	FragTrap::operator=(const FragTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::attack(const std::string& target) {
	performAttack(target, "FragTrap");
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "High five guys ! Guys.. ?" << std::endl;
}
