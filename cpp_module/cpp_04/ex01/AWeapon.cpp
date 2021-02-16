#include "AWeapon.hpp"

// name, APCost, damage를 인자로 받는 함수
AWeapon::AWeapon(std::string const &name, int APCost, int damage)
	: name(name), damage(damage), APCost(APCost)
{
}

// 복사 생성자
AWeapon::AWeapon(const AWeapon & ref)
{
    *this = ref;
}

// 소멸자
AWeapon::~AWeapon()
{
}

// 대입연산자 오버로딩
AWeapon& AWeapon::operator=(const AWeapon & ref)
{
	name = ref.name;
	APCost = ref.APCost;
	damage = ref.damage;
	return (*this);
}



// name을 반환하는 함수
std::string     AWeapon::getName() const
{
    return (name);
}

// APCost를 반환하는 함수
int             AWeapon::getAPCost() const
{
    return (APCost);
}

// damage를 반환하는 함수
int             AWeapon::getDamage() const
{
    return (damage);
}