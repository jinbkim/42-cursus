#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <cstdlib>
# include <ctime>
# include <unistd.h>

class FragTrap : virtual public ClapTrap  // 가상상속을 함으로써 나중에 ClapTrap를 상속하는 NinjaTrap을 SuperTrap클래스에서 같이 상속해도 ClapTrap가 한번만 상속됨 
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