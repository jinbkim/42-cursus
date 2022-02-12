#include "HumanA.hpp"

// 이름과 무기를 받는 생성자
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{

}

// 공격을 한다고 출력하는 함수
void    HumanA::attack()
{
    std::cout <<name<< " attacks with his " <<weapon.getType()<<'\n';
}