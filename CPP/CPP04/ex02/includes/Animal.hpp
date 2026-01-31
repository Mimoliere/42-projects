/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:13 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:16 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {

	protected:
		std::string	_type;

	public:
		Animal();
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);
		virtual ~Animal();

		virtual void	makeSound() const = 0;

		std::string	getType(void) const;
		void		setType(std::string const newType);

};

#endif
