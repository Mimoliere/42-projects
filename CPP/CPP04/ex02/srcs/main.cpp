#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

#define NBR 4

int main()
{
	Dog		dog;
	Cat*	cat = new Cat();

	dog.makeSound();
	cat->makeSound();

	delete cat;

	return (0);
}
