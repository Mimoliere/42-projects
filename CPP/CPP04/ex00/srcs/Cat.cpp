#include "../includes/Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor called" << std::endl;

	_type = "Cat";
}

Cat::Cat(const Cat& other) : Animal(other) {
	_type = other.getType();
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << "Meooow" << std::endl;
}
