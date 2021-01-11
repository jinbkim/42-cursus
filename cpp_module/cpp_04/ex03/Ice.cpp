#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::Ice(Ice const &other) : AMateria("ice")
{
	*this = other;
}

Ice::~Ice()
{
}

Ice &Ice::operator=(Ice const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}



Ice*	Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

void 	Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout <<  "* shoots an ice bolt at "<<target.getName()<<" *\n";
}