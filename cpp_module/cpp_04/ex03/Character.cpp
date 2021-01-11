#include "Character.hpp"

Character::Character(std::string name) : _name(name), _equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &other)
{
	*this = other;
}

Character::~Character()
{
	int	i = -1;

	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
}

Character &Character::operator=(Character const &other)
{
	int i = -1;

	// 반환받는 값에 존재하던 값은 모두 지워져야함
	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_name = other.getName();
	i = -1;
	// 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 
	while (other._inventory[++i])
		this->equip(other._inventory[i]->clone());
	return (*this);
}

std::string const	&Character::getName() const
{
	return (this->_name);
}



void	Character::equip(AMateria *m)
{
	if (!m || 3<this->_equipped)
		return ;
	for (int i=0; i<this->_equipped; i++)
		if (this->_inventory[i] == m)
			return ;
	this->_inventory[this->_equipped++] = m;
}

void	Character::unequip(int idx)
{
	if (idx<0 || this->_equipped<=idx)
		return ;
	while (idx < 3)
	{
		this->_inventory[idx] = this->_inventory[idx+1];
		idx++;
	}
	this->_inventory[idx] = NULL;
	(this->_equipped)--;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx<0 || _equipped<=idx)
		return ;
	this->_inventory[idx]->use(target);
}