#include "Character.hpp"

Character::Character(std::string const &name) : name(name), ap(40), weapon(NULL)
{
}

Character::Character(const Character & ref)
{
	*this = ref;
}

Character::~Character()
{
}

Character& Character::operator=(const Character & ref)
{
	name = ref.name;
	ap = ref.ap;
	weapon = ref.weapon;
	return (*this);
}



void		Character::recoverAP()
{
    ap += 10;
    if (ap > 40)
        ap = 40;
}

void		Character::equip(AWeapon* weapon)
{
    this->weapon = weapon;
}

void		Character::attack(Enemy* enemy)
{
    if (weapon==NULL || ap<weapon->getAPCost())        
        return;
    std::cout<<name<<" attacks "<<enemy->getType()<<" with a "<<weapon->getName()<<'\n';
	weapon->attack();
    ap -= weapon->getAPCost();
    enemy->takeDamage(weapon->getDamage());
    if (enemy->getHP() <= 0)  // enemy의 체력이 다달면
        enemy->~Enemy();  // enemy 소멸자 호출
}

std::string	Character::getName() const
{
    return (name);
}

int			Character::getAP() const
{
    return (ap);
}

AWeapon		*Character::getWeapon() const
{
    return (weapon);
}

std::ostream &operator<<(std::ostream &os, const Character &ref)
{
	if (ref.getWeapon())
		os<<ref.getName()<<" has "<<ref.getAP()<<" AP and wields a "<<ref.getWeapon()->getName() <<'\n';
	else
    	os<<ref.getName()<<" has "<<ref.getAP()<<" and is unarmed.\n";
	return (os);
}