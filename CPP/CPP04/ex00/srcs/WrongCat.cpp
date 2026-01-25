#include "../includes/WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor called" << std::endl;

	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {

	}
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}
