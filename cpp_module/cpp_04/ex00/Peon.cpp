#include "Peon.hpp"

Peon::Peon() : Victim()
{
    std::cout<<"Zog zog.\n";
}

Peon::Peon(std::string name) : Victim(name)
{
    std::cout<<"Zog zog.\n";
}

Peon::Peon(const Peon & ref) : Victim(ref)
{
}

Peon::~Peon()
{
	std::cout<<"Bleuark...\n";
}

Peon& Peon::operator=(const Peon &ref)
{
	name = ref.name;
    std::cout<<"Zog zog.\n";
	return (*this);
}

void    Peon::getPolymorphed() const
{
	std::cout<<name<<" has been turned into a pink pony!\n";
}