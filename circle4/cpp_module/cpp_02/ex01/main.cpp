// ex00에서 만든 Fixed 클래스를 기반으로함

// floating point란 간단하게 말하면 컴퓨터에서는 0과 1만있을뿐 사실 실수라는건 없지만 
// 실수표현을 하기위해 사용하는 기법? 어느정도의 오차가 있음

// 생성자 만들기
// 정수형을 인자로받아 fixed(8) point value로 변환되는 생성자
// 실수형을 인자로받아 fixed(8) point value로 변환되는 생성자

// toFloat : 실수로 변환하는 함수
// toInt : 정수로 변환하는 함수

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