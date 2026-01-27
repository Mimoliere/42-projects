#include "../includes/AMateria.hpp"

AMateria::AMateria(std::string const & type) {
	_type = type;
}

AMateria::AMateria(const AMateria& other) {

}

AMateria&	AMateria::operator=(const AMateria& other) {
	if (this != &other) {

	}
	return (*this);
}

AMateria::~AMateria() {

}

std::string const &	AMateria::getType() const {
	return (_type);
}
