#include "Character.hpp"

// 이름을 인자로 받는 생성자
Character::Character(std::string const &name) : name(name), ap(40), weapon(NULL)
{
}

// 복사 생성자
Character::Character(const Character & ref)
{
	*this = ref;
}

// 소멸자
Character::~Character()
{
}

// 대입연산자 오버로딩
Character& Character::operator=(const Character & ref)
{
	name = ref.name;
	ap = ref.ap;
	weapon = ref.weapon;
	return (*this);
}


// ap를 회복하는 함수
void		Character::recoverAP()
{
    ap += 10;
    if (ap > 40)  // 최대크기를 넘지못함
        ap = 40;
}

// 무기를 끼는 함수
void		Character::equip(AWeapon* weapon)
{
    this->weapon = weapon;
}

// 공격을 하는 함수
void		Character::attack(Enemy* enemy)
{
    if (weapon==NULL || ap<weapon->getAPCost())  // 무기가 없거나 ap가 부족하면  
        return;
    std::cout<<name<<" attacks "<<enemy->getType()<<" with a "<<weapon->getName()<<'\n';
	weapon->attack();
    ap -= weapon->getAPCost();  // ap 감소
    enemy->takeDamage(weapon->getDamage());
    if (enemy->getHP() <= 0)  // enemy의 체력이 다달면
        enemy->~Enemy();  // enemy 소멸자 호출
}

// 이름을 반환하는 함수
std::string	Character::getName() const
{
    return (name);
}

// ap를 반환하는 함수
int			Character::getAP() const
{
    return (ap);
}

// 무기를 반환하는 함수
AWeapon		*Character::getWeapon() const
{
    return (weapon);
}

// Character 객체도 cout에 출력이 되도록 <<연산자 오버로딩
std::ostream &operator<<(std::ostream &os, const Character &ref)
{
	if (ref.getWeapon())
		os<<ref.getName()<<" has "<<ref.getAP()<<" AP and wields a "<<ref.getWeapon()->getName() <<'\n';
	else
    	os<<ref.getName()<<" has "<<ref.getAP()<<" and is unarmed.\n";
	return (os);
}