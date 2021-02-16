#include "Peon.hpp"

// Victim의 기본생성자가 호출되고 Peon의 기본생성자가 호출됨
Peon::Peon() : Victim()
{
    std::cout<<"Zog zog.\n";
}

// Victim의 name을 인자로받는 생성자가 호출되고 Peon의 name을 인자로받는 생성자가 호출됨
Peon::Peon(std::string name) : Victim(name)
{
    std::cout<<"Zog zog.\n";
}

// Victim의 복사생성자가 호출됨
Peon::Peon(const Peon & ref) : Victim(ref)
{
}

// 소멸자
Peon::~Peon()
{
	std::cout<<"Bleuark...\n";
}

// 대입연산자 오버로딩
Peon& Peon::operator=(const Peon &ref)
{
	name = ref.name;
    std::cout<<"Zog zog.\n";
	return (*this);
}

// Peon의 getPolymorphed 함수
void    Peon::getPolymorphed() const
{
	std::cout<<name<<" has been turned into a pink pony!\n";
}