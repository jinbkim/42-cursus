#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
private:
	int					val;
	static const int	bits=8;

public:
	Fixed();  // 기본 생성자
	~Fixed();  // 소멸자
	Fixed(const Fixed &ref);  // 복사 생성자
	Fixed& operator=(const Fixed &ref);   // 대입 연산자 오버로딩

	int     getRawBits(void) const;
	void    setRawBits(int const raw);
};

#endif