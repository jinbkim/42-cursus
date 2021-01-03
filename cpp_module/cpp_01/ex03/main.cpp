// ex02 문제에서 Zombie 클래스를 재활용하여 ZombieHorde 만들기
// 정수 n개의 생성자를 가지고 있고, n개의 Zombie 객체를 만듬
// Zombie 클래스가 가지고 있는 announce() 함수도 가지고 있음
// ZombieHorde가 사라질때 메모리 해제를 해줘야함

#include "ZombieHorde.hpp"

int		main(void)
{
	ZombieHorde	z(3);  // 동적할당으로 좀비객체 3개 만듬
	z.announce();  // 좀비 객체의 울부짖음
}