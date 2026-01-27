#include "../includes/Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
	_type = other.getType();
}

Animal&	Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other.getType();
	}
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::setType(std::string const newType) {
	_type = newType;
}
