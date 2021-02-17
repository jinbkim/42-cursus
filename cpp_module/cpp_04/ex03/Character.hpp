#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string	_name;
	int			_equipped;
	AMateria	*_inventory[4];  // 4개 AMateria 저장가능

	Character();

public:
	Character(std::string name);
	Character(Character const &other);
	virtual ~Character();
	Character	&operator=(Character const &other);

	virtual std::string const	&getName() const;
	virtual void 				equip(AMateria *m);
	virtual void 				unequip(int idx);
	virtual void 				use(int idx, ICharacter &target);
};

#endif