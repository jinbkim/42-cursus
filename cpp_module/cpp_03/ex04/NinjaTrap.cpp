#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() : ClapTrap() 
{
    name = "unknown";
    hp = 60;
    maxHp = 60;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 5;
    armor = 0;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
    hp = 60;
    maxHp = 60;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 5;
    armor = 0;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

NinjaTrap::NinjaTrap(const NinjaTrap &ref)
{
    *this = ref;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

NinjaTrap& NinjaTrap::operator=(const NinjaTrap &ref)
{
	name = ref.name;
    hp = ref.hp;
    maxHp = ref.maxHp;
    ep = ref.ep;
    maxEp = ref.maxEp;
    level = ref.level;
    meleeDam = ref.meleeDam;
    rangedDam = ref.rangedDam;
    armor = ref.armor;
    return (*this);
}

NinjaTrap::~NinjaTrap()
{
    std::cout<<"[NINJA] "<<name<<" player left the game!\n";

}



void   NinjaTrap::ninjaShoebox(const FragTrap & ref)
{
    std::cout<<"[NINJA->FragTrap ] "<<name<<" attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const ScavTrap & ref)
{
    std::cout<<"[NINJA->ScavTrap] "<<name<<" attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const NinjaTrap & ref)
{
    std::cout<<"[NINJA->NinjaTrap] "<<name<<" attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const ClapTrap & ref)
{
    std::cout<<"[NINJA->ClapTrap] "<<name<<" attacks "<<ref.name<<'\n';
}      