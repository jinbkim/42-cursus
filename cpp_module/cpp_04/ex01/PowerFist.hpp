#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
public:
	PowerFist();
	PowerFist(const PowerFist &ref);
	virtual ~PowerFist();
	PowerFist& operator=(const PowerFist &ref);

	virtual void    attack() const;    
};

#endif