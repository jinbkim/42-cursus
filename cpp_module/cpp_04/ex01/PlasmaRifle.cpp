#include "PlasmaRifle.hpp"

// 기본생성자
// AWeapon의 생성자가 호출됨
PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{
}

// 복사생성자
// AWeapon의 복사생성자가 호출됨
PlasmaRifle::PlasmaRifle(const PlasmaRifle &ref) : AWeapon(ref)
{
}

// 소멸자
PlasmaRifle::~PlasmaRifle()
{
}

// 연산자 오버로딩
PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle &ref)
{
    name = ref.getName();
    APCost = ref.getAPCost();
    damage = ref.getDamage();
    return (*this);
}



// 공격을 하는 함수
void    PlasmaRifle::attack() const
{
    std::cout<<"* piouuu piouuu piouuu *\n";
}