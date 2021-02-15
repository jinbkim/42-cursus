#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap &ref);
	~FragTrap();
	FragTrap& operator=(const FragTrap &ref);

	unsigned int	vaulthunter_dot_exe(std::string const &target);
};

#endif