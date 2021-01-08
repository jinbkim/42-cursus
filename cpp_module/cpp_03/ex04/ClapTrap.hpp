#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
protected:
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

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &ref);
	virtual ~ClapTrap();
	ClapTrap& operator=(const ClapTrap &ref);

	unsigned int    rangedAttack(std::string const &target);
	unsigned int    meleeAttack(std::string const &target);
	void            takeDamage(unsigned int amount);
	void            beRepaired(unsigned int amount);
	void			show_state(void);
	unsigned int    getInfo(const std::string str);
};

#endif