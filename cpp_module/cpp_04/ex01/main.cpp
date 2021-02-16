// 주어진 조건으로 클래스 만들기
// 주어진 메인문으로 원하는 출력값 출력하기

// Enemy를 상속받은 클래스들은 takeDamage 함수를 가상함수로 정의하여 각자의 클래스에서 만든 함수로 재정의함

// AWeapon을 상속받은 클래스들은 attack 함수를 가상함수로 정의하여 각자의 클래스에서 만든 함수로 재정의함
// AWeapon의 attack는 순수 가상함수로 만들기 
// 순수 가상함수 : 선언만 있고 함수의 몸체가 정의되지 않은 가상 함수

// 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함

#include "AWeapon.hpp"
#include "PowerFist.hpp"
#include "PlasmaRifle.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "SuperMutant.hpp"

int     main(void)
{
    Character *me = new Character("me");

    std::cout << *me;

    Enemy *b = new RadScorpion();

    AWeapon *pr = new PlasmaRifle();
    AWeapon *pf = new PowerFist();

    me->equip(pr);
    std::cout << *me;
    me->equip(pf);

    me->attack(b);
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;


	// Character *me = new Character("me");

    // std::cout << *me;

    // Enemy *b = new SuperMutant();

    // AWeapon *pr = new PlasmaRifle();
    // AWeapon *pf = new PowerFist();
	// AWeapon *pf2 = new PowerFist();

    // me->equip(pr);
    // std::cout << *me;
    // me->equip(pf);

    // me->attack(b);
    // std::cout << *me;
    // me->equip(pr);
    // std::cout << *me;
    // me->attack(b);
    // std::cout << *me;
    // me->attack(b);
    // std::cout << *me;

	// me->equip(pf2);
    // std::cout << *me;
    // me->attack(b);
    // std::cout << *me;

    return 0;
}