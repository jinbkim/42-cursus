// std::exception class의 what() 함수를 오버로딩 해보는문제
// try, catch 같은 예외처리를 해보는 문제

#include "Bureaucrat.hpp"

int main()
{
    try
	{
    	Bureaucrat zero("zero", 0);
    }
	catch (std::exception const &e)
	{
        std::cerr<<e.what()<<'\n';
    }
    std::cout<<'\n';

    Bureaucrat jinbkim("jinbkim", 1);
    std::cout<<jinbkim;
    try
	{
        jinbkim.incrementGrade();
    }
	catch (std::exception const &e)
	{
        std::cerr<<e.what()<<'\n';
    }
    std::cout<<'\n';

    for (int i = 1; i < 150; i++)
        jinbkim.decrementGrade();
    std::cout<<jinbkim<<'\n';

    try {
        jinbkim.decrementGrade();
    } catch (std::exception const &e) {
        std::cerr<<e.what()<<'\n';
    }
}