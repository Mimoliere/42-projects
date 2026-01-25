#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

#pragma once

class Cat : public Animal {

	private:

	public:
		Cat();
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat();

		virtual void	makeSound() const;

};

#endif
