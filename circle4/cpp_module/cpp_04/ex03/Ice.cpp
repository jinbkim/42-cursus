#include "Ice.hpp"

// AMateria의 생성자가 호출됨
Ice::Ice() : AMateria("ice")
{
}

// AMateria의 복사생성자가 먼저 호출됨
Ice::Ice(Ice const &other) : AMateria("ice")
{
	*this = other;
}

// 소멸자
Ice::~Ice()
{
}

// 대입연산자 오버로딩
Ice &Ice::operator=(Ice const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}



// Ice 객체를 동적으로 할당받아 복제하는 함수
Ice*	Ice::clone() const
{
	Ice *copy = new Ice(*this);
	return (copy);
}

// shoot을 하는 함수
void 	Ice::use(ICharacter &target)
{
	AMateria::use(target);
	std::cout <<  "* shoots an ice bolt at "<<target.getName()<<" *\n";
}