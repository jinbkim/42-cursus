#include "Zombie.hpp"

Zombie::Zombie()
{
    name = "no name";
    type = "no type";
}

Zombie::Zombie(std::string name, std::string type)
{
    this->name = name;
    this->type = type;
}

void    Zombie::announce(void)
{
    std::cout<<"<"<<name<<" ("<<type<<")>";
    std::cout<<" Braiiiiiiinnnssss...\n";
}