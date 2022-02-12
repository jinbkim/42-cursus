#include "RadScorpion.hpp"

// Enem의 생성자가 호출되고 RadScorpion의 기본생성자가 호출됨
RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
    std::cout<<"*  click click click *\n";
}

// Enemy의 복사생성자가 호출되고 adScorpion의 복사생성자가 호출됨
RadScorpion::RadScorpion(const RadScorpion &ref) : Enemy(ref)
{
    std::cout<<"* click click click *\n"; 
}

// 대입연산자 오버로딩
RadScorpion& RadScorpion::operator=(const RadScorpion &ref)
{
    HP = ref.getHP();
    type = ref.getType();
    return (*this);
}

// 소멸자
RadScorpion::~RadScorpion()
{
    std::cout<<"* SPROTCH *\n";
}



// 데미지를 받는 함수
void	RadScorpion::takeDamage(int damage)
{
    damage -= 3;  // 3만큼 데미지를 덜받음
    if (damage >= 0)
        HP -= damage;
}