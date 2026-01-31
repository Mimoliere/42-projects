/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:07 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 15:18:12 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria {

	private:

	public:
		Ice();
		Ice(const Ice& other);
		Ice&	operator=(const Ice& other);
		~Ice();

		virtual AMateria*	clone() const;
		virtual void		use(ICharacter& target);
};

#endif
