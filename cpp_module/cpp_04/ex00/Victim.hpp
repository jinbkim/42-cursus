#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class	Victim
{
protected:
	std::string	name;

public:
	Victim();
	Victim(std::string name);
	Victim(const Victim &ref);
	virtual ~Victim();
	Victim& operator=(const Victim & ref);

    std::string getName() const;
	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	virtual void    getPolymorphed() const;
};

std::ostream& operator<<(std::ostream& os, const Victim &ref);

#endif