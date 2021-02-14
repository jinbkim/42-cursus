#include "ZombieEvent.hpp"

void    ZombieEvent::setZombieType(std::string type)
{
    this->type = type;
}

// 동적할당하여 좀비를 만드는 함수
Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie	*z = new Zombie(name, type);
	return (z);
}

void    ZombieEvent::randomChump(void)
{
	srand(time(NULL));  // 난수사용을 위해

	std::string	name;
	int		size = rand()%10+4;  // name의 크기 : 4 ~ 13 중 난수

	for(int i=0; i<size; i++)  
		name += rand()%26+'a';  // 랜덤알파벳 더하기
	Zombie	z(name, type);
	z.announce();	
}