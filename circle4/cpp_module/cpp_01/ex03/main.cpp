// ex02 문제에서 Zombie 클래스를 재활용하여 랜덤으로 생성되는 ZombieHorde 만들기
// 좀비들은 생성자엠서 객체가 만들어짐
// 동적할당된 ZombieHorde가 사라질때 소멸자에서 메모리 해제를 해줌

#include "ZombieHorde.hpp"

int		main(void)
{
	ZombieHorde	z(3);  // 동적할당으로 좀비객체 3개 만듬
	z.announce();  // 좀비 객체의 울부짖음
	std::cout<<"============\n";
}