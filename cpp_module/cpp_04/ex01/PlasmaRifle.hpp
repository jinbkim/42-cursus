#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &ref);
	virtual ~PlasmaRifle();
	PlasmaRifle& operator=(const PlasmaRifle &ref);

	virtual void	attack() const;
};

#endif