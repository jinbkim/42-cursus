#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class FragTrap
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
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &ref);
	~FragTrap();
	FragTrap& operator=(const FragTrap &ref);
	unsigned int    rangedAttack(std::string const &target);
	unsigned int    meleeAttack(std::string const &target);
	void            takeDamage(unsigned int amount);
	void            beRepaired(unsigned int amount);
	unsigned int	vaulthunter_dot_exe(std::string const &target);
	void			show_state(void);
};

#endif