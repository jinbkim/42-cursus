#include <iostream>
class MemoryException : public std::exception // 예외 클래스 정의, std::exception 상속
{
public:
	virtual const char *what() const throw() // std::exception의 가상함수 what() 구현
	{
		return "메모리 예외";
	}
};
int foo()
{
	if (1)						 // 예외조건 가정
		throw MemoryException(); // 사용자 정의 예외 클래스
	throw 0;
}
int main()
{
	try
	{
		foo();
	}
	catch (MemoryException &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "계속실행" << std::endl;
}
