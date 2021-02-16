#include "Sorcerer.hpp"

// name과 title를 인자로 받는 생성자
Sorcerer::Sorcerer(std::string name, std::string title) : name(name), title(title)
{
    std::cout<<name<<", "<<title<<", is born!\n";
}

// 복사 생성자
Sorcerer::Sorcerer(const Sorcerer & ref)
{
	*this = ref;
}

// 소멸자
Sorcerer::~Sorcerer()
{
    std::cout<<name<<", "<<title<< ", is dead. Consequenced will never be the same!\n";
}

// 대입연산자 오버로딩
Sorcerer& Sorcerer::operator=(const Sorcerer &ref)
{
	name = ref.name;
	title = ref.title;
    std::cout<<name<<", "<<title<<", is born!\n";
    return (*this);
}

// name을 반환하는 함수
std::string Sorcerer::getName() const
{
	return (name);
}

// title을 반환하는 함수
std::string Sorcerer::getTitle() const
{
	return (title);
}

// Victim클래스의 getPolymorphed함수를 가져다씀
void	Sorcerer::polymorph(Victim const &ref) const
{
	ref.getPolymorphed();
}

// cout으로 Sorcerer 객체를 출력하기위해 <<연산자 오버로딩
std::ostream& operator<<(std::ostream &os, const Sorcerer &ref)
{
    os<<"I am "<< ref.getName()<<", "<<ref.getTitle()<<", and I like ponies!\n";
	return (os);
}