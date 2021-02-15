#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &ref);
	~ScavTrap();
	ScavTrap& operator=(const ScavTrap &ref);

	void	challengeNewcomer(void);
};

#endif