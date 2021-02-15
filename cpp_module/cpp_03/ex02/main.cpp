// 상속을 써보는 문제
// 상속을 해주는 클래스의 생성자와 소멸자에 메시지를 넣어줌으로써 언제 생성자와 소멸자가 호출되는지 확인하는문제

// ClapTrap 클래스 만들기
// FragTrap 클래스와 ScavTrap 클래스는 ClapTrap 클래스를 상속받음
// 두클래스의 공통된 변수와 함수는 ClapTrap 클래스에 넣기
// ClapTrap의 생성자와 소멸자에 자체적인 메시지 넣어야함
// 따라서 ScavTrap나 FragTrap클래스의 객체가 생성될때 먼저 메세지가 호출되어야함
// 반대로 객체가 제거될때는  ScavTrap나 FragTrap클래스의 객체의 소멸자가 호출된 이후에 ClapTrap의 소멸자가 호출되어야함
// [ClapTrap] 블라블라를 넣어줬음
// ScavTrap는 FragTrap와 다르게 name에 []를 붙여줬음
// 상속을 함으로써 클래스의 공통되는 부분은 똑같이 안써도 됨

// 다른부분 
// FragTrap : vaulthunter_dot_exe
// ScavTrap : challengeNewcomer

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int		main(void)
{
	FragTrap	jinbkim("jinbkim");
	FragTrap	yapark("yapark");
	FragTrap	jakang1("jakang");
	// FragTrap	jakang2 = jakang1 랑 똑같음
	FragTrap	jakang2(jakang1);  // 복사 생성자
	FragTrap	jakang3;  // 기본 생성자

	jakang3 = jakang1;  // 대입 연산자 오버로딩
	jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	jinbkim.show_state();
	yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	yapark.show_state();

	jinbkim.beRepaired(100);  // jinbkim 회복
	jinbkim.show_state();
	yapark.beRepaired(100);  // yapark 회복
	yapark.show_state();

	std::cout<<"\n===== random attack! =====\n\n";
	for(int i=1; i<=5; i++)
	{
		std::cout<<"----- "<<i<<"st random attack! -----\n";
		usleep(1);
		jinbkim.takeDamage(yapark.vaulthunter_dot_exe(jinbkim.name));  // yapark이 랜덤무기로 jinbkim 공격
		jinbkim.show_state();
		yapark.show_state();
	}



	// ScavTrap	jinbkim("jinbkim");
	// ScavTrap	yapark("yapark");
	// ScavTrap	jakang1("jakang");
	// // ScavTrap	jakang2 = jakang1 랑 똑같음
	// ScavTrap	jakang2(jakang1);  // 복사 생성자
	// ScavTrap	jakang3;  // 기본 생성자

	// jakang3 = jakang1;  // 대입 연산자 오버로딩
	// jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	// jinbkim.show_state();
	// yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	// yapark.show_state();

	// jinbkim.beRepaired(100);  // jinbkim 회복
	// jinbkim.show_state();
	// yapark.beRepaired(100);  // yapark 회복
	// yapark.show_state();

	// std::cout<<"\n===== random challenge! =====\n\n";
	// for(int i=1; i<=3; i++)
	// {
	// 	std::cout<<"----- "<<i<<"st random challenge! -----\n";
	// 	sleep(1);
	// 	jinbkim.challengeNewcomer();  // jinbkim의 랜덤 도전
	// }
}