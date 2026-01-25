#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#pragma once

class Dog : public Animal {

	private:
		Brain*	_brain;

	public:
		Dog();
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog();

		virtual void	makeSound() const;

		Brain	getBrain() const;
		void	setBrain();

};

#endif
