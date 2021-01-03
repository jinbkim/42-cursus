// Brain 클래스 만들기
// identify : 객체의 주소를 16진수로 반환하는 함수

// Human 클래스 만들기
// Brain 클래스의 속성을 const로 가지고있음
// identify : Brain과 동일

// 아래의 코드 컴파일 하기

#include "Human.hpp"

int main()
{
	Human bob;

	// bob.identify() = brain.identify()
	std::cout << bob.identify() << std::endl;
	// bob.getBrain() = brain
	// bob.getBrain().identify() = brain.identify()
	std::cout << bob.getBrain().identify() << std::endl;
}