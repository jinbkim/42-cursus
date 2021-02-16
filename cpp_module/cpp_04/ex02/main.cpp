// 주어진 조건으로 클래스 만들기
// 주어진 메인문으로 원하는 출력값 출력하기

// Squad 클래스에서 대입연산자 오버로딩할때 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함



#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
    // ISpaceMarine* bob = new TacticalMarine;
    // ISpaceMarine* jim = new AssaultTerminator;
    // ISquad* vlc = new Squad;
    // vlc->push(bob);
    // vlc->push(jim);
    // for (int i = 0; i < vlc->getCount(); ++i)
    // {
    //     ISpaceMarine* cur = vlc->getUnit(i);
    //     cur->battleCry();
    //     cur->rangedAttack();
    //     cur->meleeAttack();
    // }

    // delete vlc;



	Squad	s1;
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;

	s1.push(bob);
	s1.push(jim);


	Squad	s2(s1);
    return 0;
}