// c++의 형변환 연산자 dynamic_cast를 사용해보는 문제
// 하위클래스의 포인터및 참조형 데이터를 상위클래스의 포인터 및 참조형 데이터로 변환
// 상위클래스의 데이터를 하위클래스의 데이터로 변환하면 NULL이 반환됨

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

// dynamic_cast로 상위클래스의 데이터를 하위클래스의 데이터로 변환하면 NULL이 반환됨
void    identify_from_pointer(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "This is A Class." << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "This is B Class." << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "This is C Class" << std::endl;
}

void    identify_from_reference(Base &p)
{
    try
    {
        Base &ref = dynamic_cast<A&>(p);
        (void)ref;
        std::cout << "This is A Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<B&>(p);
        (void)ref;
        std::cout << "This is B Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        Base &ref = dynamic_cast<C&>(p);
        (void)ref;
        std::cout << "This is C Class." << std::endl;
    }
    catch(const std::exception& e)
    {
    }
}

int     main(void)
{
    srand(time(0));

    Base* p;
    p = generate();
    identify_from_pointer(p);
    identify_from_reference(*p);
    delete p;

    std::cout << "============" << std::endl;
    
    Base* p2;
    p2 = generate();
    identify_from_pointer(p2);
    identify_from_reference(*p2);
    delete p2;

    std::cout << "============" << std::endl;
    
    Base* p3;
    p3 = generate();
    identify_from_pointer(p3);
    identify_from_reference(*p3);
    delete p3;

    std::cout << "============" << std::endl;
    
    Base* p4;
    p4 = generate();
    identify_from_pointer(p4);
    identify_from_reference(*p4);
    delete p4;

    std::cout << "============" << std::endl;
    
    Base* p5;
    p5 = generate();
    identify_from_pointer(p5);
    identify_from_reference(*p5);
    delete p5;

    std::cout << "============" << std::endl;
    
    Base* p6;
    p6 = generate();
    identify_from_pointer(p6);
    identify_from_reference(*p6);
    delete p6;
}