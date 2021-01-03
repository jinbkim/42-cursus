// Zombie 클래스 만들기
// 멤버변수 : type, name
// 멤버함수 : announce : <name (type)> Braiiiiiiinnnssss...

// ZombieEvent 클래스 만들기
// setZombieType : type 셋팅
// Zombie* newZombie(std::string name) : 새로운 Zombie 클래스 만들기
// randomChump : 랜덤이름을 가지는 새로운 Zombie 클래스 만들기

#include "ZombieEvent.hpp"

int		main(void)
{
	Zombie	z1("jinbkim", "fool");
	z1.announce();

	ZombieEvent	ze1;
	ze1.setZombieType("genius");
	Zombie	*z2 = ze1.newZombie("yapark");  // 동적할당으로 새로운 클래스 만들기
	z2->announce();
	delete(z2);  // 메모리 해제

	ZombieEvent	ze2;
	ze2.setZombieType("programmer");
	ze2.randomChump();  // 랜덤이름을 가지는 새로운 Zombie 클래스 만들기
}