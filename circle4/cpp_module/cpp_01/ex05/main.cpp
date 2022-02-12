// 클래스안에 다른클래스를 넣어 사용해보는 과제

// Brain 클래스 만들기
// identify : 객체의 주소를 반환하는 함수

// Human 클래스 만들기
// Brain 클래스의 속성을 const로 가지고있음
// identify : Brain과 동일

// 과제에서 주어진 메인문 컴파일하기

#include "Human.hpp"

int main()
{
	Human bob;

	// 둘다 결국 객체의 주소를 반환하는 함수를 출력하는것

	// bob.identify() = bob에 있는 brain의 identify()
	// bob 객체의 주소값 출력
	std::cout << bob.identify() << std::endl;
	// bob.getBrain() = bob의 brain
	// bob.getBrain().identify() = bob의 brain의 identify()
	// bob 객체의 주소값 출력
	std::cout << bob.getBrain().identify() << std::endl;
}