#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout<<"*  click click click *\n";
}

RadScorpion::RadScorpion(const RadScorpion &ref) : Enemy(ref)
{
    std::cout<<"* click click click *\n"; 
}

RadScorpion& RadScorpion::operator=(const RadScorpion &ref)
{
    HP = ref.getHP();
    type = ref.getType();
    return (*this);
}

RadScorpion::~RadScorpion()
{
    std::cout<<"* SPROTCH *\n";
}



void	RadScorpion::takeDamage(int damage)
{
    damage -= 3;
    if (damage >= 0)
        HP -= damage;
}