#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{
    name = "unknown";
    hp = FragTrap::getInfo("hp");
    maxHp = FragTrap::getInfo("maxHp");
    ep = NinjaTrap::getInfo("ep");
    maxEp = NinjaTrap::getInfo("maxEp");
    level = 1;
    meleeDam = NinjaTrap::getInfo("meleeDam");
    rangedDam = FragTrap::getInfo("rangedDam");
    armor = FragTrap::getInfo("armor");
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), FragTrap(name), NinjaTrap(name)
{
    this->name = name;
	hp = FragTrap::getInfo("hp");
    maxHp = FragTrap::getInfo("maxHp");
    ep = NinjaTrap::getInfo("ep");
    maxEp = NinjaTrap::getInfo("maxEp");
    level = 1;
    meleeDam = NinjaTrap::getInfo("meleeDam");
    rangedDam = FragTrap::getInfo("rangedDam");
    armor = FragTrap::getInfo("armor");
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
	hp = FragTrap::getInfo("hp");
    maxHp = FragTrap::getInfo("maxHp");
    ep = NinjaTrap::getInfo("ep");
    maxEp = NinjaTrap::getInfo("maxEp");
    level = 1;
    meleeDam = NinjaTrap::getInfo("meleeDam");
    rangedDam = FragTrap::getInfo("rangedDam");
    armor = FragTrap::getInfo("armor");
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