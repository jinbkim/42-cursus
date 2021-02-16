#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class	Victim
{
// private으로 선언하면 상속받은 클래스에서 접근을 못하지만
// protected로 선언하면 상속받은 클래스에서 접근이 가능
protected:
	std::string	name;

public:
	Victim();
	Victim(std::string name);
	Victim(const Victim &ref);
	virtual ~Victim(); // 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함

	Victim& operator=(const Victim & ref);

    std::string getName() const;
	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	virtual void    getPolymorphed() const;
};

std::ostream& operator<<(std::ostream& os, const Victim &ref);

#endif