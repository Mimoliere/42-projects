#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other.getType();
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "Hello euuuh.. Meow ?" << std::endl;
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void	WrongAnimal::setType(std::string const newType) {
	_type = newType;
}
