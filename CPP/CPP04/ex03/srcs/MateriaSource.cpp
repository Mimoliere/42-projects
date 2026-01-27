#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource() {
	_nb_store = 0;
}

MateriaSource::MateriaSource(const MateriaSource& other) {
	_nb_store = other.getNbStore();

	for (int i = 0; i < _nb_store; i++)
		_storage[i] = other._storage[i]->clone();
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _nb_store; i++)
			delete _storage[i];
	
		_nb_store = other.getNbStore();
		for (int i = 0; i < _nb_store; i++)
			_storage[i] = other._storage[i]->clone();
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _nb_store; i++)
		delete _storage[i];
}

int const	MateriaSource::getNbStore() const {
	return (_nb_store);
}

void	MateriaSource::learnMateria(AMateria* m) {
	if (_nb_store == MAX_STORAGE)
		return ;

	_storage[_nb_store++] = m;
}

AMateria*	MateriaSource::createMateria(std::string const & type) {
	AMateria*	ret;

	for (int i = 0; i < _nb_store; i++) {
		if (_storage[i]->getType().compare(type) == 0) {
			ret = _storage[i]->clone();
			return (ret);
		}
	}

	return (0);
}
