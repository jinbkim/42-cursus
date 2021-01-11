#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(Cure const &other) : AMateria("cure")
{
	*this = other;
}

Cure::~Cure()
{
}

Cure& Cure::operator=(Cure const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}



Cure*	Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

void	Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals "<<target.getName()<<"’s wounds *\n";
}