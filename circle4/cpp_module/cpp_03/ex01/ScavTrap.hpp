#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class ScavTrap
{
private:
	int    hp;
	int    maxHp;
	int    ep;
	int    maxEp;
	int    level;
	int    meleeDam;
	int    rangedDam;
	int    armor;

public:
	std::string	name;
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ref);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &ref);
	unsigned int    rangedAttack(std::string const &target);
	unsigned int    meleeAttack(std::string const &target);
	void            takeDamage(unsigned int amount);
	void            beRepaired(unsigned int amount);
	void			show_state(void);
	void            challengeNewcomer(void);
};

#endif