#include "Fixed.hpp"

// 값이 0으로 초기화되는 기본 생성자
Fixed::Fixed()
{
	std::cout<<"Default constructor called\n";
	val = 0;
}

// 소멸자
Fixed::~Fixed(void)
{
    std::cout<<"Destructor called\n";
}

// 복사생성자
// 인자가 참조형이 아니면 생성자와 복사생성자 호출로 인해 무한루프에 빠짐
Fixed::Fixed(const Fixed &ref) 
{
    std::cout<<"Copy constructor called\n";
    val = ref.getRawBits();   // 그냥 getRawBits함수만 써서 값을 얻느냐
	// *this = ref;  // 오버로딩 연산자를 쓰느냐
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


// 값을 반환하는 함수
int     Fixed::getRawBits(void) const
{
    std::cout<<"getRawBits member function called\n";
    return (val);
}

// 값을 변경하는 함수
void    Fixed::setRawBits(int const raw)
{
    val = raw;
}