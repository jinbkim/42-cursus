#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"

class AMateria;

// interface class : 가상소멸자와 가상함수로만 이루어진 클래스
class ICharacter
{
public:
	virtual ~ICharacter() {}

	virtual std::string const	&getName() const = 0;
	virtual void 				equip(AMateria* m) = 0;
	virtual void 				unequip(int idx) = 0;
	virtual void 				use(int idx, ICharacter& target) = 0;
};

#endif