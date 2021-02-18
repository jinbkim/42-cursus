// pdf에서 class 만들라고 한거대로 만들기

// Form객체 만들기
// Form(std::string name, int signGrade, int executeGrade)
// signGrade 이상부터 sign가능, executeGrade 이상부터  execute가능
// executeGrade내용은 ex02에 나옴

// Form 객체를 cout으로 출력하기위해 <<연산자 오버로딩을 해줌

#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
	Form 		*f1;
	try
	{
		f1 = new Form("f1", 0, 10);  // 1등급보다 높아서 예외처리
	}
	catch(const std::exception &e)
	{
		std::cout<<e.what()<<'\n';
	}

	Bureaucrat	b("b", 50);  // 50등급
	Form 		f2("f2", 60, 10);  // 60등급부터 sign가능
	Form 		f3("f3", 40, 10);  // 40등급부터 sign가능
	try
	{
		b.signForm(f2);  // 60등급보다 높은 50등급이라 sign 가능
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		b.signForm(f3);  // 40등급보다 낮은 50등급이라 예외처리
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
    return 0;
}