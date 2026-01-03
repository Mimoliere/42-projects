#include "../includes/Zombie.hpp"

int	main(void) {
	Zombie*	zombie;

	std::cout << "Oh look, a zombie in the stack !" << std::endl;
	randomChump("Solomon Grundy");

	std::cout << "And now on the heap ?!" << std::endl;
	zombie = newZombie("Ryuma");
	std::cout << "Wait, is it friendly ?" << std::endl;
	zombie->announce();
	std::cout << "You were a worthy opponent..." << std::endl;
	delete zombie;

	return (0);
}
