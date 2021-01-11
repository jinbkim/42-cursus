#include "Enemy.hpp"

Enemy::Enemy(int HP, std::string const & type) : HP(HP), type(type)
{
}

Enemy::Enemy(const Enemy &ref)
{
	*this = ref;
}

Enemy::~Enemy()
{
}

Enemy& Enemy::operator=(const Enemy &ref)
{
	HP = ref.HP;
	type = ref.type;
	return (*this);
}



std::string     Enemy::getType() const
{
    return (type);
}

int             Enemy::getHP() const
{
    return (HP);
}

void            Enemy::takeDamage(int damage)
{
    HP -= damage;
    if (HP < 0)  // hp는 0이하로 떨어질수 없음
        HP = 0;
}