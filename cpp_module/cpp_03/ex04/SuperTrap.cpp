#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 20;
    armor = 5;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 20;
    armor = 5;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";	
}

SuperTrap::SuperTrap(const SuperTrap & ref)
{
    *this = ref;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";	
}


SuperTrap& SuperTrap::operator=(const SuperTrap & ref)
{
    this->name = ref.name;
	hp = ref.hp;
    maxHp = ref.maxHp;
    ep = ref.maxHp;
    maxEp = ref.maxEp;
    level = ref.level;
    meleeDam = ref.rangedDam;
    rangedDam = ref.rangedDam;
    armor = ref.armor;
    return (*this);    
}

SuperTrap::~SuperTrap()
{
	std::cout<<"[SUPER] "<<name<<" player left the game!\n";
}


unsigned int    SuperTrap::rangedAttack(std::string const &target)
{
    return (FragTrap::rangedAttack(target));
}

unsigned int    SuperTrap::meleeAttack(std::string const &target)
{
    return (NinjaTrap::meleeAttack(target));
}