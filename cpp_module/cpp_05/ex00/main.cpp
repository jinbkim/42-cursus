// pdf에서 class 만들라고 한거대로 만들기

// 예외상황에서 예외처리 문법에 대해 공부하는 과제
// 예외상황 : 구현한 프로그램이 논리에 맞지 않는 상황

// try : 예외가 있는지 탐색을 하는 부분
// throw : try에서 예외를 탐색하면 throw의 인자로 준 변수를 catch로 던짐
// catch : throw에서 던진 변수를 인자로 받아 catch 내부에 정의된 예외처리를 실시

// grade는 1등부터 150등까지 있음
// 1등보다 높거나 150등보다 낮으면 예외처리를 해주기

// std::exception class : 모든 예외 처리 클래스는 이 클래스를 상속받음

// Bureaucrat 객체를 cout으로 출력하기위해 <<연산자 오버로딩을 해줌

#include "Bureaucrat.hpp"

int     main(void)
{
	Bureaucrat A("A", 1);  // A의 등수 : 1등

	std::cout<<A;  // <<연산자를 오버로딩하여 Bureaucrat 객체가 출력가능
	try
    {
        A.upGrade(); // A의 등수를 1높임 0등이됨 예외가 발생함
    }
    catch(const std::exception& e)  // throw로 던진 클래스를 받음
    {
        std::cout << e.what() << '\n';  // 오버라이딩한 what함수의 반환값 출력
    }

	Bureaucrat *B;
	try
	{
		B = new Bureaucrat("B", 151);
	}
	catch(const std::exception& e)  // throw로 던진 클래스를 받음
	{
		std::cout<<e.what()<<'\n';  // 오버라이딩한 what함수의 반환값 출력
	}
    return 0;
}