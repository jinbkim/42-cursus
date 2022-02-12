#include "Convert.hpp"

// 생성자
Convert::Convert(std::string str, double value) :_str(str), _double(value)
{
}

// 복사생성자
Convert::Convert(const Convert& ref)
{
    *this = ref;
}

// 대입연산자 오버로딩
Convert&    Convert::operator=(const Convert& ref)
{
    if (this == &ref)
        return (*this);
    _str = ref.getStr();
    _double = ref.getDouble();
    return (*this);
}

// 소멸자
Convert::~Convert()
{
}

// str을 반환하는 함수
std::string Convert::getStr() const
{
    return (_str);
}

// double을 반환하는 함수
double      Convert::getDouble() const
{
    return (_double);
}  

// char형으로 변환
void    Convert::toChar()
{
    int integer;

    std::cout << "char: ";
    integer = static_cast<int>(_double);  // 일단 int로 형변환, 정수가 아닌 실수라면 소수점자리가 날라감
    if (integer - _double != 0)  // 다르다는건 double 변수가 정수가 아닌 실수 이므로 char로 변환 불가능
        throw Convert::ImpossibleException();
    else if (integer >= 32 && integer <= 126)  // displayable 할때
        std::cout << "'" << static_cast<char>(_double) << "'" << std::endl;  // char로 형변환하여 출력
    else  // non displayable 할때
        throw Convert::NonDisplayableException();
}

// int형으로 변환
// isnan : 인자가 실수가 아니면 true, 아니면 false 반환
// isinf : 인자가 무한대값이면 true, 아니면 false 반환
// stol : 문자열을 정수(long)로
void    Convert::toInt()
{
    long comp;

    std::cout << "int: ";
    if (std::isnan(_double) || std::isinf(_double))  // 실수가 아니거나, 무한대 값이면
        throw Convert::ImpossibleException();
    comp = stol(_str);
    if (comp > INT_MAX || comp < INT_MIN)  // int 범위를 넘어가면
        throw Convert::ImpossibleException();
    std::cout << static_cast<int>(_double) << std::endl;  // int로 형변환 하여 출력
}

// float형으로 변환
void    Convert::toFloat()
{
    int integer;

    std::cout << "float: ";
    std::cout << static_cast<float>(_double);  // float로 형변환 하여 출력

    integer = static_cast<int>(_double);
    if (integer - _double == 0)  // double 변수가 정수가 아닌 실수이면
        std::cout << ".0f" << std::endl;
    else  // double 변수가 정수이면
        std::cout << "f" << std::endl;
}

// double형으로 변환
void    Convert::toDouble()
{
    int integer;

    std::cout << "double: ";
    std::cout << static_cast<double>(_double);  // double로 형변환 하여 출력

    integer = static_cast<int>(_double);
	if (integer - _double == 0)  // double 변수가 정수가 아닌 실수이면
        std::cout << ".0" ;
    std::cout << std::endl;
}

// std::exception 예외처리 객체를 상속받아 what함수를 재정의
const char* Convert::ImpossibleException::what() const throw()
{
    return (" impossible");
}

// std::exception 예외처리 객체를 상속받아 what함수를 재정의
const char* Convert::NonDisplayableException::what() const throw()
{
    return (" Non displayable");
}