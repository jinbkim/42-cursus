#ifndef Cure_HPP
# define Cure_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(Cure const &other);
	virtual ~Cure();
	Cure& operator=(Cure const &other);

	virtual Cure	*clone() const;
	virtual void 	use(ICharacter &target);
};

#endif