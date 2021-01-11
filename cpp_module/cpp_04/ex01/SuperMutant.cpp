#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(70, "SuperMutant")
{
    std::cout<<"Gaaah. Me want smash heads!\n";
}

SuperMutant::SuperMutant(const SuperMutant &ref) : Enemy(ref)
{
    std::cout<<"Gaaah. Me want smash heads!\n"; 
}

SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh...\n";
}

SuperMutant& SuperMutant::operator=(const SuperMutant & ref)
{
    HP = ref.getHP();
    type = ref.getType();
    return (*this);
}



void            SuperMutant::takeDamage(int damage)
{
    damage -= 3;
    if (damage >= 0)
        HP -= damage;
}