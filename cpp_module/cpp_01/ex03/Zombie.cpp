#include "Zombie.hpp"

Zombie::~Zombie()  // 객체가 사라질때 자동으로 호출되는 소멸자
{
	std::cout<<name<<" is died\n";
}

void    Zombie::announce(void)
{
    std::cout<<"<"<<name<<" ("<<type<<")>";
    std::cout<<" Braiiiiiiinnnssss...\n";
}

void	Zombie::initZombie(std::string name, std::string type)
{
 	this->name = name;
    this->type = type;
}