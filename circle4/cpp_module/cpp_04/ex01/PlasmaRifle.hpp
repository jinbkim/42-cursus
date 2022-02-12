#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon  // AWeapony을 상속받음
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &ref);
	virtual ~PlasmaRifle();  // 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함
	PlasmaRifle& operator=(const PlasmaRifle &ref);

	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	// AWeapon의 attack처럼 동작하지않고 PlasmaRifle에서 함수를 재정의함
	virtual void	attack() const;
};

#endif