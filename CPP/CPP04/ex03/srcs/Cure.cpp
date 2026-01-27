#include "../includes/Cure.hpp"

Cure::Cure() : AMateria("cure") {
}

Cure::Cure(const Cure& other) : AMateria(other) {

}

Cure&	Cure::operator=(const Cure& other) {
	if (this != &other) {
		AMateria::operator=(other);
	}
	return (*this);
}

Cure::~Cure() {

}

AMateria*	Cure::clone() const {
	Cure*	newCure = new Cure();

	return (newCure);
}

void	Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
