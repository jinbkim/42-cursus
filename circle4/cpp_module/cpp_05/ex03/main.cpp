// Intern 클래스만 추가됨
// 인턴한테 일을 시킴

// 크기가 3인 포인터배열로 일단 존재하는 form객체의 주소값을 담음
// 여기서 사용하는 객체를 고를때 if / else if / else if / else(제대로 된값이 아닐때) 처럼 못생기게 하지말아야함

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int     main(void)
{
	Intern a, b, c, d;
	Bureaucrat jinbkim = Bureaucrat("jinbkim", 1);  // 1등급이라 모든 걸 승인하고 실행가능

	std::cout<<"===================================\n";
	Form *f1 = a.makeForm("shrubbery creation", "42 cluster");
	jinbkim.signForm(*f1);
	jinbkim.executeForm(*f1);

	std::cout<<"===================================\n";
	Form *f2 = b.makeForm("robotomy request", "dog");
	jinbkim.signForm(*f2);
	jinbkim.executeForm(*f2);

	std::cout<<"===================================\n";
	Form *f3 = c.makeForm("presidential pardon", "moon");
	jinbkim.signForm(*f3);
	jinbkim.executeForm(*f3);

	std::cout<<"===================================\n";
	try
	{
		d.makeForm("jinbkim", "moon");  // 이상한값을 넣어서 예외처리가됨
	}
	catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

	delete f1;
	delete f2;
	delete f3;

    return (0);    
}