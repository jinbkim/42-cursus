#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string	name;
	std::string	type;

public:
	~Zombie();
	void    announce(void);  // 울부짖는 함수
	void	initZombie(std::string name, std::string type);  // 이름과 타입을 초기화 시키는 함수
};

#endif