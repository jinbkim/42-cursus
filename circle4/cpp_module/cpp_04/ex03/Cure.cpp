#include "Cure.hpp"

// AMateria의 생성자가 호출됨
Cure::Cure() : AMateria("cure")
{
}

// AMateria의 복사 생성자가 먼저 호출됨
Cure::Cure(Cure const &other) : AMateria("cure")
{
	*this = other;
}

// 소멸자
Cure::~Cure()
{
}

// 대입 연산자 오버로딩
Cure& Cure::operator=(Cure const &other)
{
	this->_type = other._type;
	this->_xp = other._xp;
	return (*this);
}



// Cure 객체를 동적으로 할당받아 복제하는 함수
Cure*	Cure::clone() const
{
	Cure *copy = new Cure(*this);
	return (copy);
}

// heal을 하는 함수
void	Cure::use(ICharacter& target)
{
	AMateria::use(target);
	std::cout << "* heals "<<target.getName()<<"’s wounds *\n";
}