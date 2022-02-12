#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : virtual public ClapTrap // 가상상속을 함으로써 나중에 ClapTrap를 상속하는 FragTrap을 SuperTrap클래스에서 같이 상속해도 ClapTrap가 한번만 상속됨
{
public:
	NinjaTrap();
	NinjaTrap(std::string name);
	NinjaTrap(const NinjaTrap &ref);
	~NinjaTrap();
	NinjaTrap& operator=(const NinjaTrap &ref);

	void   ninjaShoebox(const FragTrap &ref);
	void   ninjaShoebox(const ScavTrap &ref);
	void   ninjaShoebox(const NinjaTrap &ref);
	void   ninjaShoebox(const ClapTrap &ref);   
};

#endif