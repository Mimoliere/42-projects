#include "../includes/Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor called" << std::endl;

	_type = "Dog";
}

Dog::Dog(const Dog& other) : Animal(other) {
	_type = other.getType();
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}
