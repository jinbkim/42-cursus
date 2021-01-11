#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &ref) : AWeapon(ref)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &ref)
{
    name = ref.getName();
    APCost = ref.getAPCost();
    damage = ref.getDamage();
    return (*this);
}



void    PlasmaRifle::attack() const
{
    std::cout<<"* piouuu piouuu piouuu *\n";
}