#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n)
{
	srand(time(NULL));  // 난수사용을 위해

	std::string	name;
	std::string	type[3] = {"student", "baeksu", "programmer"};
	int		size;

	this->n=n;
	zom = new Zombie[n];
	for(int i=0; i<n; i++)
	{
		name.clear();
		size = rand()%10+4;  // name의 크기 : 4 ~ 13 중 난수
		for(int j=0; j<size; j++)  
			name += rand()%26+'a';  // 랜덤알파벳 더하기
		zom[i].initZombie(name, type[rand()%3]);
	}
}

// 모든 좀비가 소리지르는 함수
void		ZombieHorde::announce(void)
{
	for(int i=0; i<n; i++)
		zom[i].announce();
}

// ZombieHorde 객체가 소멸될때 자동으로 호출되는 소멸자
ZombieHorde::~ZombieHorde()
{
	std::cout<<"before ZombieHorde delete!\n";
	delete[] zom;
	std::cout<<"after ZombieHorde delete!\n";
}