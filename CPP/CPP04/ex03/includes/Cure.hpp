#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

#pragma once

class Cure : public AMateria {

	private:

	public:
		Cure();
		Cure(const Cure& other);
		Cure&	operator=(const Cure& other);
		~Cure();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
