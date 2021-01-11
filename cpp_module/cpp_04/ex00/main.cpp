// Sorcerer 클래스 만들기
// 멤버변수 : name, title
// birth : NAME, TITLE, is born!
// death : NAME, TITLE, is dead. Consequences will never be the same!
// introduce : I am NAME, TITLE, and I like ponies!

// Victim 클래스 만들기
// 멤버변수 : name
// birth : Some random victim called NAME just appeared!
// death : Victim NAME just died for no apparent reason!
// introduce : I'm NAME and I like otters!

// Peon 클래스 만들기
// birth : "Zog zog."
// death : "Bleuark..."
// introduce : I am NAME, TITLE, and I like ponies!

// 주어진 메인문으로 원하는 출력값을 출력하기

#include "Sorcerer.hpp"
#include "Peon.hpp"

int main()
{
	Sorcerer	robert("Robert", "the Magnificent");
	Victim		jim("Jimmy");
	Peon		joe("Joe");

	std::cout<<robert<<jim<<joe;
	robert.polymorph(jim);
	robert.polymorph(joe);

	// Sorcerer	a;  // 인자없이 만들수 없음

	return 0;
}