/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:09:44 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:09:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

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
