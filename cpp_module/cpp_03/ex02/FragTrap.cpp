#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 100;
    maxEp = 100;
    level = 1;
    meleeDam = 30;
    rangedDam = 20;
    armor = 5;
	std::cout<<name<<" player joined the game!\n"; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 100;
    maxEp = 100;
    level = 1;
    meleeDam = 30;
    rangedDam = 20;
    armor = 5;
	std::cout<<name<<" player joined the game!\n"; 
}

FragTrap::FragTrap(const FragTrap &ref)
{
    *this = ref;
	std::cout<<name<<" player joined the game!\n"; 
}

FragTrap& FragTrap::operator=(const FragTrap & ref)
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

FragTrap::~FragTrap()
{
    std::cout << name << " player left the game!\n";
}



unsigned int	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	srand(time(NULL));

	if (ep < 25)
	{
        std::cout<<name<<" is out of energy!\n";
        return (0);
	}
	ep -= 25;
	std::string	attack[] = {"fist", "wooden stick", "arrow", "pistol", "mahine gun"};
	int		damage[] = {10, 20, 30, 40, 50};
	int		idx;
	idx = rand()%5;
	std::cout<<name<<" attacks "<<target<< " with "<< attack[idx] 
	<< " causing "<< damage[idx] << " points of damage!\n";
	return (damage[idx]);
}