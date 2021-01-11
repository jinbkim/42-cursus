#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"

class SuperMutant : public Enemy 
{
public:
	SuperMutant();
	SuperMutant(const SuperMutant &ref);
	~SuperMutant();
	SuperMutant& operator=(const SuperMutant &ref);

	virtual void takeDamage(int damage);
};

# endif