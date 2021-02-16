#include "PowerFist.hpp"

// 기본생성자
// AWeapon의 생성자가 호출됨
PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

// 복사생성자
// AWeapon의 복사생성자가 호출됨
PowerFist::PowerFist(const PowerFist &ref) : AWeapon(ref)
{
}

// 소멸자
PowerFist::~PowerFist()
{
}

// 연산자 오버로딩
PowerFist& PowerFist::operator=(const PowerFist &ref)
{
    name = ref.getName();
    APCost = ref.getAPCost();
    damage = ref.getDamage();
    return (*this);
}



// 공격을 하는 함수
void    PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *\n";
}