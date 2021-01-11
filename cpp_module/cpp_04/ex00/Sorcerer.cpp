#include "Sorcerer.hpp"

Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
    std::cout<<name<<", "<<title<<", is born!\n";
}

Sorcerer::Sorcerer(const Sorcerer & ref)
{
	*this = ref;
}

Sorcerer::~Sorcerer()
{
    std::cout<<name<<", "<<title<< ", is dead. Consequenced will never be the same!\n";
}

Sorcerer& Sorcerer::operator=(const Sorcerer &ref)
{
	name = ref.name;
	title = ref.title;
    std::cout<<name<<", "<<title<<", is born!\n";
    return (*this);
}

std::string Sorcerer::getName() const
{
	return (name);
}

std::string Sorcerer::getTitle() const
{
	return (title);
}

void	Sorcerer::polymorph(Victim const &ref) const
{
	ref.getPolymorphed();
}

std::ostream& operator<<(std::ostream &os, const Sorcerer &ref)
{
    os<<"I am "<< ref.getName()<<", "<<ref.getTitle()<<", and I like ponies!\n";
	return (os);
}