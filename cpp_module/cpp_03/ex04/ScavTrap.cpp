#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 50;
    maxEp = 50;
    level = 1;
    meleeDam = 20;
    rangedDam = 15;
    armor = 3;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 50;
    maxEp = 50;
    level = 1;
    meleeDam = 20;
    rangedDam = 15;
    armor = 3;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

ScavTrap::ScavTrap(const ScavTrap &ref)
{
    *this = ref;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

ScavTrap& ScavTrap::operator=(const ScavTrap & ref)
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

ScavTrap::~ScavTrap()
{
    std::cout<<'['<<name<<"] player left the game!\n";
}



void            ScavTrap::challengeNewcomer(void)
{
	srand(clock());
	std::string	chall[5] =
	{
		"You have to get up at 7 am!",
		"You shouldn't rest even on weekends!",
		"You have to study English every day!",
		"Reduce the time you spend watching YouTube!",
		"You should exercise every day!"
	};
	int idx = rand()%5;
	std::cout<<'['<<name<<"] : "<<chall[idx]<<'\n';
}