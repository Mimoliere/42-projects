#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal*	meta = new Animal();
	const Animal*	j = new Dog();
	const Animal*	i = new Cat();
	const WrongAnimal*	wrongAnimal = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << std::endl << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	std::cout << std::endl << wrongCat->getType() << " " << std::endl << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	wrongCat->makeSound();
	wrongAnimal->makeSound();
	std::cout << std::endl;

	delete (meta);
	delete (j);
	delete (i);
	delete (wrongAnimal);
	delete (wrongCat);

	return 0;
}
