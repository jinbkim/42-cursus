#include "Enemy.hpp"

// hp와 type을 인자로 받는 생성자
Enemy::Enemy(int HP, std::string const & type) : HP(HP), type(type)
{
}

// 복사생성자
Enemy::Enemy(const Enemy &ref)
{
	*this = ref;
}

// 소멸자
Enemy::~Enemy()
{
}

// 대입연산자 오버로딩
Enemy& Enemy::operator=(const Enemy &ref)
{
	HP = ref.HP;
	type = ref.type;
	return (*this);
}


// type을 반환하는 함수
std::string     Enemy::getType() const
{
    return (type);
}

// hp를 반환하는 함수
int             Enemy::getHP() const
{
    return (HP);
}

// 데미지를 받는 함수
void            Enemy::takeDamage(int damage)
{
    HP -= damage;
    if (HP < 0)  // hp는 0이하로 떨어질수 없음
        HP = 0;
}