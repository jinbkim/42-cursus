#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

// 이름과 무기(참조자)를 가지는 함수
class HumanA
{
private:
	std::string	name;
	Weapon	&weapon;  // 참조자

public:
    HumanA(std::string name, Weapon& weapon);  // 이름과 무기를 받는 생성자
	void	attack();  // 공격을 한다고 출력하는 함수
};


#endif