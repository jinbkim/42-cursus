#include "FragTrap.hpp"

FragTrap::FragTrap()
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

FragTrap::FragTrap(std::string name)
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

unsigned int    FragTrap::rangedAttack(std::string const &target)
{
	std::cout<<name<< " attacks "<<target<<" at range, causing " 
	<<rangedDam<<" points of damage!\n";
    return (rangedDam);
}

unsigned int    FragTrap::meleeAttack(std::string const &target)
{
    std::cout<<name<< " attacks "<<target<<" at melee, causing " 
	<<meleeDam<<" points of damage!\n";
    return (meleeDam);
}

void    FragTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)
	{
		std::cout<<name<<" already dead!\n";
		return ;
	}
	int damage = amount-armor;

	if (damage < 0)
		damage = 0;
	hp -= damage;
	std::cout<<name<<" takes "<< damage<<" point(s) of damage!\n";
	if (hp <= 0)
	{
		hp = 0;
		std::cout<<name<<" dead!\n";
	}
}

void    FragTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	ep += amount;
	if (maxHp < hp)
		hp = maxHp;
	if (maxEp < ep)
		ep = maxEp;
	std::cout<<name<<" repaired "<<amount<<" point(s)! of hit and energy!\n";
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

void			FragTrap::show_state(void)
{
	std::cout<<"------------------\n";
	std::cout<<"name : "<<name<<'\n';
	std::cout<<"hp : "<<hp<<'\n';
	std::cout<<"ep : "<<ep<<'\n';
	std::cout<<"------------------\n";

}