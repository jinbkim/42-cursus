#include "TacticalMarine.hpp"

// 기본 생성자
TacticalMarine::TacticalMarine()
{
    std::cout<<"Tactical Marine ready for battle!\n";
}

// 복사 생성자
TacticalMarine::TacticalMarine(const TacticalMarine &ref)
{
	(TacticalMarine)ref;
    std::cout<<"Tactical Marine ready for battle!\n";
}

// 대입연산자
TacticalMarine& TacticalMarine::operator=(const TacticalMarine &ref)
{
	(TacticalMarine)ref;
    return (*this);
}

// 소멸자
TacticalMarine::~TacticalMarine()
{
    std::cout<<"Aaargh...\n";
}

// TacticalMarine 객체를 동적으로 할당받아 복제하는 함수
TacticalMarine* TacticalMarine::clone() const
{
    TacticalMarine *copy = new TacticalMarine(*this);
    return (copy);
}

// 그냥 만들라고해서 만든함수들
void TacticalMarine::battleCry() const
{
    std::cout<<"For the holy PLOT!\n";
}

void TacticalMarine::rangedAttack() const
{
    std::cout<<"* attacks with a bolter *\n";
}

void TacticalMarine::meleeAttack() const
{
    std::cout << "* attacks with a chainsword *\n";    
}