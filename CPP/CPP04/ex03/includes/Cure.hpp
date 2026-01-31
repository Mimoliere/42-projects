/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:02 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

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
