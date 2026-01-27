#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

#define MAX_STORAGE 4

#pragma once

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
