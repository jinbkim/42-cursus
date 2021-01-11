#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist &ref) : AWeapon(ref)
{
}

PowerFist::~PowerFist()
{
}

PowerFist& PowerFist::operator=(const PowerFist &ref)
{
    name = ref.getName();
    APCost = ref.getAPCost();
    damage = ref.getDamage();
    return (*this);
}



void    PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *\n";
}