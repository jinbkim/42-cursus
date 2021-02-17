// 주어진 조건으로 클래스 만들기
// 주어진 메인문으로 원하는 출력값 출력하기

// TacticalMarine와 AssaultTerminator 클래스는 ISpaceMarine를 상속받음
// 같은 함수들을 상속받았지만 ISpaceMarine에서 가상함수정의 하였기때문에, 각각의 클래스에서 재정의 해줌으로써 다른동작을함 

// Squad 클래스에서 대입연산자 오버로딩할때 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함
// Squad 객체는 사라질때 소멸자에서 가지고있는 units들을 모두 메모리 해제시킴
// 대입연산자 오버로딩에서는 이미 전에 객체가 존재하면 지우고 시작해야됨
// *this = other 이런식으로 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
        ISpaceMarine* cur = vlc->getUnit(i);
        cur->battleCry();
        cur->rangedAttack();
        cur->meleeAttack();
    }

    delete vlc;



	// Squad	s1;
    // ISpaceMarine* bob = new TacticalMarine;
    // ISpaceMarine* jim = new AssaultTerminator;

	// s1.push(bob);
	// s1.push(jim);
	// s1.push(jim);


	// Squad	s2(s1);
	// std::cout<<"===================\n";
	// s1 = s2;
	// std::cout<<"===================\n";
    return 0;
}