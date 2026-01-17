#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) {
	_name = name;
	_weapon = NULL;
}

HumanB::~HumanB() {

}

void	HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;	// L'adresse de l'objet auquel weapon fait référence
}

void	HumanB::attack() {
	if (_weapon == NULL) {
		std::cout << _name << " has no weapon !!!" << std::endl;
		return ;
	}

	std::cout << _name << " attacks with their " << _weapon->getType();
	std::cout << std::endl;
}
