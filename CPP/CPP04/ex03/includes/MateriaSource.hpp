/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:24 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:26 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MAX_STORAGE 4

class MateriaSource : public IMateriaSource {

	private:
		AMateria*	_storage[MAX_STORAGE];
		int			_nb_store;

	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource();

		int const	getNbStore() const;

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
