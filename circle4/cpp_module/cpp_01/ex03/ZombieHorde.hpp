#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"
#include <cstdlib>
#include <time.h>

class ZombieHorde
{
private:
	Zombie	*zom;
	int		n;

public:
	ZombieHorde(int n);  // 좀비객체들을 만드는 생성자
	void    announce(void);  // 객체들이 울부짖는 함수
	~ZombieHorde();  // 객체가 소멸될때 호출되는 소멸자
};

#endif