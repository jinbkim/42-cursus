#include "Victim.hpp"

// 기본 생성자
Victim::Victim()
{
	name = "unknown";
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

// name을 인자로 받는 생성자
Victim::Victim(std::string name) : name(name)
{
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

// 복사생성자
Victim::Victim(const Victim &ref)
{
    *this = ref;
	std::cout<<"Some random victim called "<<name<<" just appeared!\n";
}

// 소멸자
Victim::~Victim()
{
    std::cout<<"Victim "<< name<<" just died for no apparent reason!\n";
}

// 대입연사자 오버로딩
Victim& Victim::operator=(const Victim &ref)
{
	name = ref.name;
	return (*this);
}

// name을 반환하는 함수
std::string Victim::getName() const
{
    return (name);
}

// Victim클래스의 getPolymorphed
void        Victim::getPolymorphed() const
{
    std::cout<<name<<" has been turned into a cute little sheep!\n";
}

// cout으로 Victim 객체를 출력하기위해 <<연산자 오버로딩
std::ostream& operator<<(std::ostream &os, const Victim &ref)
{
	os<< "I am "<<ref.getName()<<" and I like otters!\n";
	return (os);
}