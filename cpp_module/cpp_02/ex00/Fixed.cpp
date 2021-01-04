#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called\n";
	val = 0;
}

Fixed::~Fixed(void)
{
    std::cout<<"Destructor called\n";
}

// 복사생성자
// 인자가 참조형이 아니면 생성자와 복사생성자 호출로 인해 무한루프에 빠짐
Fixed::Fixed(const Fixed &ref) 
{
    std::cout<<"Copy constructor called\n";
    val = ref.getRawBits(); 
}

// 인자가 참조형임
// 인자가 참조형이 아니면 복사생성자가 호출됨
// 반환값이 참조형임
// 반환값이 참조형이 아니면 복사생성자가 호출됨
Fixed&	Fixed::operator=(const Fixed &ref)
{
    std::cout<<"Assignation operator called\n";
    val = ref.getRawBits();
    return (*this);
}



int     Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called\n";
    return (val);
}

void    Fixed::setRawBits(int const raw)
{
    val = raw;
}