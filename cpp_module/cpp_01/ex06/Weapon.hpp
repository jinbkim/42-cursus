#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	std::string	type;

public:
	Weapon(std::string type);  // 무기를 받는 생성자
	std::string const	&getType(void);  // 가지고 있는 무기를 반환하는 함수
	void	setType(std::string);  // 가지고 있는 무기를 변경하는 함수
};

#endif