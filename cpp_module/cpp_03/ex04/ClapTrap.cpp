#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    name = "unknown";
    std::cout<<"[ClapTrap] "<<name<<" player joined the game!\n"; 
}

ClapTrap::ClapTrap(std::string name) : name(name)
{
	std::cout<<"[ClapTrap] "<<name<<" player joined the game!\n"; 
}

ClapTrap::ClapTrap(const ClapTrap & ref)
{
    *this = ref;
	std::cout<<"[ClapTrap] "<<name<<" player joined the game!\n"; 
}

ClapTrap::~ClapTrap()
{
	std::cout<<"[ClapTrap] "<<name<<" player left the game!\n";
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
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



unsigned int    ClapTrap::rangedAttack(std::string const &target)
{
	std::cout<<name<< " attacks "<<target<<" at range, causing " 
	<<rangedDam<<" points of damage!\n";
    return (rangedDam);
}

unsigned int    ClapTrap::meleeAttack(std::string const &target)
{
    std::cout<<name<< " attacks "<<target<<" at melee, causing " 
	<<meleeDam<<" points of damage!\n";
    return (meleeDam);
}

void    ClapTrap::takeDamage(unsigned int amount)
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

void    ClapTrap::beRepaired(unsigned int amount)
{
	hp += amount;
	ep += amount;
	if (maxHp < hp)
		hp = maxHp;
	if (maxEp < ep)
		ep = maxEp;
	std::cout<<name<<" repaired "<<amount<<" point(s)! of hit and energy!\n";
}

void	ClapTrap::show_state(void)
{
	std::cout<<"------------------\n";
	std::cout<<"name : "<<name<<'\n';
	std::cout<<"hp : "<<hp<<'\n';
	std::cout<<"ep : "<<ep<<'\n';
	std::cout<<"------------------\n";
}

unsigned int    ClapTrap::getInfo(const std::string str)
{
    if (str == "hp")
        return (hp);
    else if (str == "maxHp")
        return (maxHp);
    else if (str == "ep")
        return (ep);
    else if (str == "maxEp")
        return (maxEp);
    else if (str == "level")
        return (level);
    else if (str == "meleeDam")
        return (meleeDam);
    else if (str == "rangedDam")
        return (rangedDam);
    else if (str == "armor")
        return (armor);
    return (0);
}