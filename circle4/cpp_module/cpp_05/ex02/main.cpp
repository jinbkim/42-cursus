// pdf에서 class 만들라고 한거대로 만들기

// 세 클래스모두 Form를 상속받음
// Form클래스의 execute함수를 순수 가상함수로 선언함으로써 이를 상속받은 하위클래스에서 execute함수를 재정의함

// ShrubberyCreationForm
// 관목숲을 만듬
// 관목숲 만들기를 승인 하려면 145등급 이상이어야함
// 관목숲을 만드려면 137등급 이상 이어야함

// RobotomyRequestForm
// 50퍼 확률로 해당 인자를 로봇화를 함 
// 로봇화하기를 승인하려면 72등급 이상이어야함
// 로봇화하기를 하려면 45등급 이상 이어야함

// PresidentialPardonForm
// 대통령 탄핵하기
// 대통력 탄핵을 승인하려면 25등급 이상이어야함
// 대통령을 탄핵 하려면 5등급 이상 이어야함

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
	ShrubberyCreationForm	s("42 cluster");
	Bureaucrat				jinbkim1("jinbkim", 130);  // 130등급이라 승인과 실행 둘다 가능
	jinbkim1.signForm(s);  // 승인가능
	jinbkim1.executeForm(s);  // 실행가능

	std::cout<<"=======================================\n";
	RobotomyRequestForm r("dog");
	Bureaucrat			jinbkim2("jinbkim", 50);  // 50등급이라 승인은 가능하지만 실행은 불가능
	jinbkim2.signForm(r);  // 승인가능
	jinbkim2.executeForm(r);  // 실행불가능

	std::cout<<"=======================================\n";
	PresidentialPardonForm p("moon");
    Bureaucrat jinbkim3("jinbkim", 30);  // 30등급이라 승인과 실행 둘다 불가능
    jinbkim3.signForm(p);  // 승인 불가능
    jinbkim3.executeForm(p);  // 실행 불가능
}