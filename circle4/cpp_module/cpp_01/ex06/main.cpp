// Weapon 클래스 만들기
// type : string 타입의 멤버변수
// getType : 상수 참조로 문자열 type을 반환하는 함수
// setType : type을 세팅하는 함수

// HumanA, HumanB 클래스 만들기
// 두 클래스 모두 Weapon 클래스와, name, attack() 을 가짐
// attack : NAME attacks with his WEAPON_TYPE
// 아래코드가 주어진 상태에서 두클래스중 어느 클래스가 포인터 혹은 참조자로 저장되야 하는가?

// HumanA는 포인터와 참조자 둘다 가능하지만 참조자가 더좋음
// 포인터대신 쓰기편하며 중간에 무기를 바꾸지않아서

// HumanB는 포인터만 가능
// 참조자는 선언과 동시에 초기화를 해야하는데 그렇게하지 못하기 때문

// 참조자는 사실상 별칭임(사실상 똑같은것?). 포인터는 가리키는것.

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		// HumanA bob은 무기를 바꾸지 않음
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);  // HumanA bob은 생성자를 이용하여 무기를 장착함
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		// HumanB jim은 생성자를 이용하여 무기를 장착하지 않음
		// 만약 HumanB jim의 Weapon객체를 참조자로 선언을 한다면 문제가 생김
		// 이유는 참조자는 선언과 동시에 초기화를 해야하는 규칙이 있음
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}