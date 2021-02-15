// canonical form을 지켜야함
// 클래스 하나에 기본생성자, 복사생성자, 대입 연산자 오버로딩, 소멸자 하나씩은 있어야함

// canonical form 을 맞추기위해 기본생성자, 복사생성자, 대입 연산자 오버로딩, 소멸자를 만들어보는 과제
// 주어진 메인문에 주어진 결과가 나오도록 Fixed.hpp, Fixed.cpp 만들기

// 과제로 주어진것
// private members
// fixed point 값이 저장될 정수형 변수
// 항상 8의 값을 가지는 fractional bits가 저장될 static 정수형 상수.

// public members
// 0으로 초기화시키는 기본 생상자
// 소멸자
// 복사 생성자
// 대입 연산자 오버로딩
// getRawBits : 값을 반환하는 함수
// setRawBits : 값을 변경하는 함수

#include "Fixed.hpp"

// 과제와 똑같은 결과가 나오는것을 알 수 있음
int main(void)
{
	Fixed a;  // 기본 생성자
	Fixed b(a);  // 복사생성자
	Fixed c;  // 기본 생성자

	c = b;  // 대입 연산자 오버로딩

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}