/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:16 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:19 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {};

		virtual void		learnMateria(AMateria*) = 0;
		virtual AMateria*	createMateria(std::string const & type) = 0;
};

#endif
