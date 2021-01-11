#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
    std::cout<<"* teleports from space *\n";
}

AssaultTerminator::AssaultTerminator(const AssaultTerminator &ref)
{
    *this = ref;
    std::cout<<"* teleports from space *\n";
}

AssaultTerminator& AssaultTerminator::operator=(const AssaultTerminator &ref)
{
	(AssaultTerminator)ref;
    return (*this);  
}

AssaultTerminator::~AssaultTerminator()
{
    std::cout<<"I'll be back...\n";
}

AssaultTerminator* AssaultTerminator::clone() const
{
    AssaultTerminator *copy = new AssaultTerminator(*this);
    return (copy);
}



void AssaultTerminator::battleCry() const
{
    std::cout << "This code is unclean. PURIFY IT!\n";
}

void AssaultTerminator::rangedAttack() const
{
    std::cout << "* does nothing *\n";
}

void AssaultTerminator::meleeAttack() const
{
    std::cout << "* attacks with chainfists *\n";    
}