// 생성자 만들기
// 정수형을 인자로받아 fixed(8) point value로 변환되는 생성자
// 실수형을 인자로받아 fixed(8) point value로 변환되는 생성자

// toFloat : fixed point로 실수로 변환하는 함수
// toInt : fixed point로 정수로 변환하는 함수

// Fixed 객체도 cout에 나올수 있도록 << 연산자 오버로딩

#include "Fixed.hpp"

int 	main(void)
{
	Fixed 		a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}