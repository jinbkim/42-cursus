#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const &name, int APCost, int damage)
	: name(name), damage(damage), APCost(APCost)
{
}

AWeapon::AWeapon(const AWeapon & ref)
{
    *this = ref;
}

AWeapon::~AWeapon()
{
}

AWeapon& AWeapon::operator=(const AWeapon & ref)
{
	name = ref.name;
	APCost = ref.APCost;
	damage = ref.damage;
	return (*this);
}



std::string     AWeapon::getName() const
{
    return (name);
}

int             AWeapon::getAPCost() const
{
    return (APCost);
}

int             AWeapon::getDamage() const
{
    return (damage);
}