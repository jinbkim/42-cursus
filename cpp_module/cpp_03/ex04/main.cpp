// SuperTrap 클래스 만들기
// FragTrap 클래스와 NinjaTrap 클래스를 둘다 상속

// Hit points (Fragtrap)
// Max hit points (Fragtrap)
// Energy points (Ninjatrap)
// Max energy points (Ninjatrap)
// Level (1)
// Name (Parameter of constructor)
// Melee attack damage (Ninjatrap)
// Ranged attack damage (Fragtrap)
// Armor damage reduction (Fragtrap)
// rangedAttack (Fragtrap)
// meleeAttack (Ninjatrap)

// 두 클래스의 special attacks 을 가짐

// 가상상속으로 겹치는 상위클래스를 한번만 상속할수 있음

#include "SuperTrap.hpp"

int     main(void)
{
	SuperTrap	a;
	std::cout<<"============================\n";
	SuperTrap	jinbkim("jinbkim");
	SuperTrap	yapark("yapark");
	SuperTrap	jakang1("jakang");
	// SuperTrap	jakang2 = jakang1 랑 똑같음
	SuperTrap	jakang2(jakang1);  // 복사 생성자
	SuperTrap	jakang3;  // 기본 생성자

	jakang3 = jakang1;  // 대입 연산자 오버로딩
	std::cout<<"========================================\n";
	jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	jinbkim.show_state();
	yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	yapark.show_state();

	jinbkim.beRepaired(100);  // jinbkim 회복
	jinbkim.show_state();
	yapark.beRepaired(100);  // yapark 회복
	yapark.show_state();

	std::cout<<"========================================\n";
	std::cout<<"\n===== random attack! =====\n\n";
	for(int i=1; i<=5; i++)
	{
		std::cout<<"----- "<<i<<"st random attack! -----\n";
		usleep(1);
		jinbkim.takeDamage(yapark.vaulthunter_dot_exe(jinbkim.name));  // yapark이 랜덤무기로 jinbkim 공격
		jinbkim.show_state();
		yapark.show_state();
	}

	std::cout<<"\n===== ninjaShoebox attack! =====\n\n";
	ClapTrap    hjung("hjung");
	FragTrap    kycho("kycho");
    ScavTrap    jikang("jikang");
	jinbkim.ninjaShoebox(hjung);
	jinbkim.ninjaShoebox(kycho);
	jinbkim.ninjaShoebox(jikang);
	std::cout<<"\n=================================\n\n";
}