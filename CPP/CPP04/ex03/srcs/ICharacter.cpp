#include "../includes/ICharacter.hpp"

ICharacter::ICharacter() {

}

ICharacter::ICharacter(const ICharacter& other) {

}

ICharacter&	ICharacter::operator=(const ICharacter& other) {
	if (this != &other) {

	}
	return (*this);
}

ICharacter::~ICharacter() {

}
