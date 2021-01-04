// 주어진 메인문에 주어진 결과가 나오도록 Fixed.hpp, Fixed.cpp 만들기

// private members
// 값이 저장될 정수형 변수
// 항상 8의 값을 가지는 fractional bits가 저장될 static 정수형 상수.

// public members
// 0으로 초기화시키는 기본 생상자
// 소멸자
// 대입 연산자 오버로딩
// getRawBits : 값을 반환하는 함수
// setRawBits : 값을 변경하는 함수

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b(a);
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}