// FragTrap 클래스 만들기

// 멤버 변수
// Hit points (100)
// Max hit points (100)
// Energy points (100)
// Max energy points (100)
// Level (1)
// Name (Parameter of constructor)
// Melee attack damage (30)
// Ranged attack damage (20)
// Armor damage reduction (5)

// 멤버 함수
// rangedAttack(std::string const & target)
// meleeAttack(std::string const & target)
// takeDamage(unsigned int amount)
// beRepaired(unsigned int amount)

// 생성자와 소멸자가 호출될때 표시하기

// hit의 최대값은 max hit
// energy의 최댜값은 max energy
// repair를 계속해도 hit의 최대값은 max hit, 최소값은 0

// 랜덤으로 공격하는 vaulthunter_dot_exe 함수 만들기
// 이 공격을 하면 25 에너지가 소비됨

#include "FragTrap.hpp"

int     main(void)
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
		sleep(1);
		jinbkim.takeDamage(yapark.vaulthunter_dot_exe(jinbkim.name));  // yapark이 랜덤무기로 jinbkim 공격
		jinbkim.show_state();
		yapark.show_state();
	}
}