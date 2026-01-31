/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:26 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:28 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

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
