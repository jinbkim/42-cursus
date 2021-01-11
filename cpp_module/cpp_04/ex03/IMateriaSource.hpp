#ifndef IMATERIA_SOURCE_HPP
# define IMATERIA_SOURCE_HPP

#include "AMateria.hpp"

// interface class : 가상소멸자와 가상함수로만 이루어진 클래스
class IMateriaSource
{
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif