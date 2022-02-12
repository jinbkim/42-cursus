#include "HumanB.hpp"

// 이름을 받는 생성자
HumanB::HumanB(std::string name)
{
    this->name = name;
}

// 무기를 변경하는 함수
void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

// 공격을 한다고 출력하는 함수
void    HumanB::attack()
{
    std::cout<<name<<" attacks with his "<<weapon->getType()<<'\n';
}