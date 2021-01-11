#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int			_count;
	AMateria	*_materia[4];
public:
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	virtual ~MateriaSource();
	MateriaSource& operator=(MateriaSource const &other);

	virtual void 		learnMateria(AMateria*);
	virtual AMateria	*createMateria(std::string const &type);
};

#endif