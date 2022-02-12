#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					val;  // fixed point 값이 저장될 정수형 변수
	static const int	bits=8;  // 항상 8의 값을 가지는 fractional bits가 저장될 static 정수형 상수.

public:
	Fixed();  // 기본 생성자
	~Fixed();  // 소멸자
	Fixed(const Fixed &ref);  // 복사 생성자
	Fixed& operator=(const Fixed &ref);   // 대입 연산자 오버로딩

	int     getRawBits(void) const;  // 값을 반환하는 함수
	void    setRawBits(int const raw);  // 값을 변경하는 함수
};

#endif