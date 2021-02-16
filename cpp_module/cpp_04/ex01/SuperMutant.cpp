#include "SuperMutant.hpp"

// Enemy의 생성자가 호출된후에 SuperMutant의 기본생성자가 호출됨
SuperMutant::SuperMutant() : Enemy(70, "SuperMutant") 
{
    std::cout<<"Gaaah. Me want smash heads!\n";
}

// Enemy의 복사생성자가 호출된후에 SuperMutant의 복사생성자가 호출됨
SuperMutant::SuperMutant(const SuperMutant &ref) : Enemy(ref)
{
    std::cout<<"Gaaah. Me want smash heads!\n"; 
}

// 소멸자
SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh...\n";
}

// 대입연산자 오버로딩
SuperMutant& SuperMutant::operator=(const SuperMutant & ref)
{
    HP = ref.getHP();
    type = ref.getType();
    return (*this);
}



// 데미지를 받는 함수 
// to take 3 less damage points than normal
void            SuperMutant::takeDamage(int damage)
{
    damage -= 3;  // 3 적제 데미지를 받음
    if (damage >= 0)  
        HP -= damage;
}