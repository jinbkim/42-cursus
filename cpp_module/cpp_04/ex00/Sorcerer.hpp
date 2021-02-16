#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
// private으로 선언하면 상속받은 클래스에서 접근을 못하지만
// protected로 선언하면 상속받은 클래스에서 접근이 가능
protected:
	std::string	name;
	std::string	title;

public:
    Sorcerer();  // 선언만하고 내용은 만들지 않음. 선언이라도 한이유는 Coplien's form을 지키기위해
	Sorcerer(std::string name, std::string title);
    Sorcerer(const Sorcerer &ref);
    ~Sorcerer();
    Sorcerer& operator=(const Sorcerer &ref);

	std::string getName() const;
	std::string getTitle() const;
	void		polymorph(Victim const &ref) const;
};

std::ostream& operator<<(std::ostream &os, const Sorcerer &ref);

#endif