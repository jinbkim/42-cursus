// 주어진 메인문으로 원하는 출력값을 출력되도록 클래스만들기
// Sorcerer 클래스 만들기
// Victim 클래스 만들기
// Peon 클래스 만들기

// 가상함수에 대해 알아가는 문제

// Peon은 Victim을 상속받음
// Victim에서 getPolymorphed를 가상함수로 만들어주면서 Victim을 상속받은 Peon에서 getPolymorphed를 재정의함

// 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함

// Sorcerer클래스는 매개변수가 없으면 객체를 못만들게 만들어야함

#include "Sorcerer.hpp"
#include "Peon.hpp"

int main()
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout<<robert<<jim<<joe;
	robert.polymorph(jim);
	robert.polymorph(joe);  // Victim에서 polymorph를 가상함수로 만들었기 때문에 Peon에서 재정의한 함수가 호출됨

	// Sorcerer	a;  // 인자없이 만들수 없음

	return 0;
}