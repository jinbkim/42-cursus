// 주어진 조건으로 클래스 만들기
// 주어진 메인문으로 원하는 출력값 출력하기

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