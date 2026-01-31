/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:22 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:24 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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
