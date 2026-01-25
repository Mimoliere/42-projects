#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

#pragma once

class WrongAnimal {

	protected:
		std::string	_type;

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& other);
		WrongAnimal&	operator=(const WrongAnimal& other);
		virtual ~WrongAnimal();

		void	makeSound() const;

		std::string	getType(void) const;
		void	setType(std::string const newType);

};

#endif
