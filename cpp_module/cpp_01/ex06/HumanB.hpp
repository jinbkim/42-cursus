#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

// 이름과 무기(포인터)를 가지는 함수
class HumanB
{
private:
	std::string	name;
	Weapon	*weapon;  // 포인터

public:
	HumanB(std::string name);  // 이름을 받는 생성자
    void    setWeapon(Weapon &weapon);  // 무기를 변경하는 함수
	void    attack();  // 공격을 한다고 출력하는 함수
};

#endif