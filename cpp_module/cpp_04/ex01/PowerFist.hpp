#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"

class PowerFist : public AWeapon  // AWeapony을 상속받음
{
public:
	PowerFist();
	PowerFist(const PowerFist &ref);
	virtual ~PowerFist();  // 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함
	PowerFist& operator=(const PowerFist &ref);

	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	// AWeapon의 attack처럼 동작하지않고 PowerFist에서 함수를 재정의함
	virtual void    attack() const;    
};

#endif