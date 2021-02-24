// c++의 형변환 연산자 dynamic_cast를 사용해보는 문제
// 보통 안전한 down cast를 할때 사용함
// down cast : 상위클래스의 포인터및 참조형 데이터를 하위클래스의 포인터 및 참조형 데이터로 변환
// 상위클래스가 polymorphic 클래스(하나 이상의 가상함수를 가지는 클래스)일때만 down cast 가능
// 변환 실패시 NULL pointer 반환

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

// 랜덤으로 객체 생성
Base    *generate(void)
{
    Base    *p;
	
	srand(clock());
    int     num = rand();

    if (num % 3 == 0)
        return (p = new A);
    else if (num % 3 == 1)
        return (p = new B);
    else
        return (p = new C);
}

// down cast를 할때 p가 가리키고있는 객체 포인터의 자료형이 다르면 NULL이 반환됨
void    identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is A Class." << '\n';
    else if (dynamic_cast<B*>(p))
        std::cout << "This is B Class." << '\n';
    else if (dynamic_cast<C*>(p))
        std::cout << "This is C Class" << '\n';
}

void    identify_from_reference(Base &p)
{
    try
    {
        Base &ref = dynamic_cast<A&>(p);  // p가 A객체로 만들어진게 아니면 예외발생. catch로 감
        (void)ref;
        std::cout << "This is A Class." << '\n';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<B&>(p);  // p가 B객체로 만들어진게 아니면 예외발생. catch로 감
        (void)ref;
        std::cout << "This is B Class." << '\n';
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<C&>(p);  // p가 C객체로 만들어진게 아니면 예외발생. catch로 감
        (void)ref;
        std::cout << "This is C Class." << '\n';
    }
    catch(const std::exception& e)
    {
    }
}

int     main(void)
{
    srand(time(0));

    Base* p;
    p = generate();  // 랜덤으로 객체 생성
    identify_from_pointer(p);  // 만든 객체 말해줌
    identify_from_reference(*p);  // 만든 객체 말해줌
    delete p;
}