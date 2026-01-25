#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

#pragma once

class Cat : public Animal {

	private:
		Brain*	_brain;

	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		virtual void	makeSound() const;

		Brain	getBrain() const;
		void	setBrain();

};

#endif
