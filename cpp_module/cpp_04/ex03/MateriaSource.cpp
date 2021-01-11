#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

MateriaSource::~MateriaSource()
{
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	for (int i=0; i<this->_count; i++)
	{
		delete _materia[i];
		this->_materia[i] = NULL;
	}
	for (int i=0; i<other._count; i++)
		this->learnMateria(other._materia[i]);
	return (*this);
}



void		MateriaSource::learnMateria(AMateria *m)
{	
	if (3<this->_count || !m)
		return ;
	this->_materia[this->_count++] = m->clone();
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i=0; i<this->_count; i++)
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	return (0);
}
