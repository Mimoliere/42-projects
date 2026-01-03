#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	std::cout << _name << " was destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}
