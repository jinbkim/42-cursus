#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					val;  // floating point value가 저장되는 변수
	static const int	bits=8;

public:
	Fixed();  // 기본 생성자
	Fixed(int const val);  // 안자가 정수일때 생성자
    Fixed(float const val);  // 인자가 실수일때 생성자
	Fixed(const Fixed &ref);  // 복사 생성자
	~Fixed();  // 소멸자
	Fixed& operator=(const Fixed &ref);   // 대입 연산자 오버로딩

	int     getRawBits(void) const;  // 값을 반환하는 함수
	void    setRawBits(int const raw);  // 값을 변경하는 함수
	float   toFloat(void) const;  // 실수로 변환
    int     toInt(void) const;  // 정수로 변환
};

std::ostream& operator<<(std::ostream& os, const Fixed &ref);  // Fixed 객체도 cout에 나올수 있도록 << 연산자 오버로딩

#endif