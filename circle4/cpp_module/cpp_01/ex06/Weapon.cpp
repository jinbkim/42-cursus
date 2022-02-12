#include "Weapon.hpp"

// 무기를 받는 생성자
Weapon::Weapon(std::string type) : type(type)
{
    
}

// 가지고 있는 무기를 반환하는 함수
std::string const &Weapon::getType(void)
{
    return (type);
}

// 가지고 있는 무기를 변경하는 함수
void    Weapon::setType(std::string type)
{
    this->type = type;
}