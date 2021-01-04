#include "Fixed.hpp"

Fixed::Fixed() : val(0)
{
    std::cout<<"Default constructor called\n";
}

Fixed::Fixed(const Fixed &ref) : val(ref.val)
{
    std::cout<<"Copy constructor called\n";
}

Fixed::Fixed(int const val)
{
    std::cout<<"Int constructor called"<<std::endl;
    this->val = val<<bits;  // 2^8 곱하기
}

Fixed::Fixed(float const val)
{
    std::cout<<"Float constructor called"<<std::endl;
    this->val = roundf(val*(1<<bits));  // 2^8 곱하기
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called"<<std::endl;
}

Fixed&  Fixed::operator=(const Fixed &ref)
{
    std::cout<<"Assignation operator called\n";
	val = ref.getRawBits();
	return (*this);
}



int     Fixed::getRawBits(void) const
{
    return (val);
}

void    Fixed::setRawBits(int const raw)
{
    val = raw;
}

int     Fixed::toInt(void) const
{
    return (val>>bits);  // 2^8 나누기
}

float   Fixed::toFloat(void) const
{
    return ((float)val/(1<<bits));  // 2^8 나누기
}



std::ostream& operator<<(std::ostream &os, const Fixed &ref)  // Fixed 객체도 cout에 나올수 있도록 << 연산자 오버로딩
{
    return (os<<ref.toFloat());  // output stream에 Fixed 객체의 val를 실수로 변환한값 넣기
}