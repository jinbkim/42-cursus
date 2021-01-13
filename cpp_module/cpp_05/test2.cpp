#include <iostream>
using namespace std;

class Exception : public std::exception // 예외 클래스 정의, std::exception 상속
{
public :
	// std::exception의 what() 함수를 override
	virtual const char *what() const throw()
	{
		return ("jinbkim what!()\n");
	}
};

int		main(void)
{
	try
	{
		Exception	e;
		throw(e);
	}
	catch(Exception &e)
	{
		cout<<e.what()<<'\n';
	}
}