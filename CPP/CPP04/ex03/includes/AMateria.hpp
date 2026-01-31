/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:51 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:53 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

class ICharacter;

class AMateria {

	protected:
		std::string	_type;

	public:
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);
		virtual ~AMateria();

		std::string	const & getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
