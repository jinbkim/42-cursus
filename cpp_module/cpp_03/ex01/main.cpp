// ex00에서 만든 FragTrap 클래스 + ScavTrap 클래스 만들기

// ScavTrap 클래스 만들기
// FragTrap와 초기값이 조금 달라짐

// FragTrap과 같은 함수를 쓰지만 생성자, 소멸자, 공격함수에서 출력하는 문장들이 달라야함
// FragTrap에서는 이름에 []를 붙여줬음

// 이클래스 에서는 랜덤으로 공격하는 vaulthunter_dot_exe 함수가 없음
// 대신 랜덤으로 challenge하는 challengeNewcomer 함수 만들기

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int     main(void)
{
	// FragTrap	jinbkim("jinbkim");
	// FragTrap	yapark("yapark");
	// FragTrap	jakang1("jakang");
	// // FragTrap	jakang2 = jakang1 랑 똑같음
	// FragTrap	jakang2(jakang1);  // 복사 생성자
	// FragTrap	jakang3;  // 기본 생성자

	// jakang3 = jakang1;  // 대입 연산자 오버로딩
	// jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	// jinbkim.show_state();
	// yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	// yapark.show_state();

	// jinbkim.beRepaired(100);  // jinbkim 회복
	// jinbkim.show_state();
	// yapark.beRepaired(100);  // yapark 회복
	// yapark.show_state();

	// std::cout<<"\n===== random attack! =====\n\n";
	// for(int i=1; i<=5; i++)
	// {
	// 	std::cout<<"----- "<<i<<"st random attack! -----\n";
	// 	usleep(10);  // srand(clock()) 함수가 1us 기준으로 난수를 생성하기때문에 조금 쉬었음
	// 	jinbkim.takeDamage(yapark.vaulthunter_dot_exe(jinbkim.name));  // yapark이 랜덤무기로 jinbkim 공격
	// 	jinbkim.show_state();
	// 	yapark.show_state();
	// }



	ScavTrap	jinbkim("jinbkim");
	ScavTrap	yapark("yapark");
	ScavTrap	jakang1("jakang");
	// ScavTrap	jakang2 = jakang1 랑 똑같음
	ScavTrap	jakang2(jakang1);  // 복사 생성자
	ScavTrap	jakang3;  // 기본 생성자

	jakang3 = jakang1;  // 대입 연산자 오버로딩
	jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	jinbkim.show_state();
	yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	yapark.show_state();

	jinbkim.beRepaired(100);  // jinbkim 회복
	jinbkim.show_state();
	yapark.beRepaired(100);  // yapark 회복
	yapark.show_state();

	std::cout<<"\n===== random challenge! =====\n\n";
	for(int i=1; i<=3; i++)
	{
		std::cout<<"----- "<<i<<"st random challenge! -----\n";
		usleep(10);  // srand(clock()) 함수가 1us 기준으로 난수를 생성하기때문에 조금 쉬었음
		jinbkim.challengeNewcomer();  // jinbkim의 랜덤 도전
	}
}