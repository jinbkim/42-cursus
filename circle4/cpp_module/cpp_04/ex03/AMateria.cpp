#include "AMateria.hpp"

// type을 인자로받는 생성자
AMateria::AMateria(std::string const &type) : _type(type), _xp(0)
{
}

// 복사생성자
AMateria::AMateria(AMateria const &other)
{
	*this = other;
}

// 소멸자
AMateria::~AMateria()
{
}

// 대입연산자 오버로딩
AMateria& AMateria::operator=(AMateria const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}



// type을 반환하는 함수
std::string const&	AMateria::getType() const
{
	return (this->_type);
}

// xp를 반환하는 함수
unsigned int 		AMateria::getXP() const
{
	return (this->_xp);
}

// xp를 10 증가시키는 함수
void 				AMateria::use(ICharacter &target)
{
	this->_xp += 10;
	(void)target;
}