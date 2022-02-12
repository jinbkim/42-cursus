#include "AssaultTerminator.hpp"

// 기본 생성자
AssaultTerminator::AssaultTerminator()
{
    std::cout<<"* teleports from space *\n";
}

// 복사 생성자
AssaultTerminator::AssaultTerminator(const AssaultTerminator &ref)
{
	(AssaultTerminator)ref; 
    std::cout<<"* teleports from space *\n";
}

// 대입연산자 오버로딩
AssaultTerminator& AssaultTerminator::operator=(const AssaultTerminator &ref)
{
	(AssaultTerminator)ref;
    return (*this);  
}

// 소멸자
AssaultTerminator::~AssaultTerminator()
{
    std::cout<<"I'll be back...\n";
}

// AssaultTerminator 객체를 동적으로 할당받아 복제하는 함수
AssaultTerminator* AssaultTerminator::clone() const
{
    AssaultTerminator *copy = new AssaultTerminator(*this);
    return (copy);
}



// 만들라고해서 만든함수
void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!\n";
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *\n";    
}