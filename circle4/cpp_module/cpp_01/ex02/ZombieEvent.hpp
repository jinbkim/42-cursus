#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <time.h>

class ZombieEvent
{
private:
	std::string type;

public:
	void    setZombieType(std::string type);
	void    randomChump();
	Zombie* newZombie(std::string name);
};

#endif