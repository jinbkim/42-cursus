#include "Victim.hpp"

Victim::Victim()
{
	name = "unknown";
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

Victim::Victim(std::string name) : name(name)
{
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

Victim::Victim(const Victim &ref)
{
    *this = ref;
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

Victim::~Victim()
{
    std::cout<<"Victim "<< name<<" just died for no apparent reason!\n";
}

Victim& Victim::operator=(const Victim &ref)
{
	name = ref.name;
	return (*this);
}

std::string Victim::getName() const
{
    return (name);
}

void        Victim::getPolymorphed() const
{
    std::cout<<name<<" has been turned into a cute little sheep!\n";
}

std::ostream& operator<<(std::ostream &os, const Victim &ref)
{
	os<< "I am "<<ref.getName()<<" and I like otters!\n";
	return (os);
}