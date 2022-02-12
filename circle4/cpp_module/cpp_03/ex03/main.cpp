// ClapTrap를 상속받은 NinjaTrap 클래스 만들기

// 멤버변수의 초기값이 FragTrap과 ScavTrap과 조금 다름 (pdf에 나와있음)

// special attack인 ninjaShoebox 함수 만들기
// 함수의 인자를 각각 다른 클래스를 참조자로 받음
// 각각 다른 클래스를 참조자로 인자만 다른 ninjaShoebox 함수를 오버로딩 하여 4개 만들기
// 각각 다른 동작을 함
// 자유롭게 만들기

#include "NinjaTrap.hpp"

int		main(void)
{
	NinjaTrap	jinbkim("jinbkim");
	// NinjaTrap	yapark("yapark");
	// NinjaTrap	jakang1("jakang");
	// // NinjaTrap	jakang2 = jakang1 랑 똑같음
	// NinjaTrap	jakang2(jakang1);  // 복사 생성자
	// NinjaTrap	jakang3;  // 기본 생성자

	// jakang3 = jakang1;  // 대입 연산자 오버로딩
	// jinbkim.takeDamage(yapark.rangedAttack(jinbkim.name));  // yapark이 jinbkim angedAttack
	// jinbkim.show_state();
	// yapark.takeDamage(jinbkim.meleeAttack(yapark.name));  // jinbkim이 yapark meleeAttack
	// yapark.show_state();

	// jinbkim.beRepaired(100);  // jinbkim 회복
	// jinbkim.show_state();
	// yapark.beRepaired(100);  // yapark 회복
	// yapark.show_state();

	std::cout<<"\n===== ninjaShoebox attack! =====\n\n";
	
	ClapTrap    hjung("hjung");
	FragTrap    kycho("kycho");
    ScavTrap    jikang("jikang");

	jinbkim.ninjaShoebox(hjung);
	jinbkim.ninjaShoebox(kycho);
	jinbkim.ninjaShoebox(jikang);
	
	std::cout<<"\n=================================\n\n";
}