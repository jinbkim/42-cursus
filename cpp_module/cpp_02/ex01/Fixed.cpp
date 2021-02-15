#include "Fixed.hpp"

// 기본생성자
Fixed::Fixed() : val(0)
{
    std::cout<<"Default constructor called\n";
}

// 복사생성자
Fixed::Fixed(const Fixed &ref)
{
    std::cout<<"Copy constructor called\n";
	*this = ref;
}

// 인자가 정수일때 생성자
Fixed::Fixed(int const val)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->val = val<<bits;  // 비트연산 : 2^8 곱하기
	// std::cout<<"this->val : "<<this->val<<'\n';
}

// 인자가 실수일때 생성자
Fixed::Fixed(float const val)
{
    std::cout<<"Float constructor called"<<std::endl;
	// roundf : 가장가까운 fixed point 값으로 변환하주는 함수
    this->val = roundf(val*(1<<bits));  // 비트연산 : 2^8 곱하기
	// std::cout<<"this->val : "<<this->val<<'\n';
}

// 소멸자
Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

// 대입연산자 오버로딩
Fixed&  Fixed::operator=(const Fixed &ref)
{
    std::cout<<"Assignation operator called\n";
	val = ref.getRawBits();
	return (*this);
}



// 값을 반환하는 함수
int     Fixed::getRawBits(void) const
{
    return (val);
}

// 값을 변경하는 함수
void    Fixed::setRawBits(int const raw)
{
    val = raw;
}

// 정수로로 변환하는 함수
int     Fixed::toInt(void) const
{
    return (val>>bits);  // 비트연산 : 2^8 나누기
}

// 실수로 변환하는 함수
float   Fixed::toFloat(void) const
{
    return ((float)val/(1<<bits));  // 비트연산 : 2^8 나누기
}



// <<연산자 오버로딩
std::ostream& operator<<(std::ostream &os, const Fixed &ref)  // Fixed 객체도 cout에 나올수 있도록 << 연산자 오버로딩
{
    return (os<<ref.toFloat());  // output stream에 Fixed 객체의 val를 실수로 변환한값 넣기
}