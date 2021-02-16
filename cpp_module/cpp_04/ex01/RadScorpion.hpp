#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion : public Enemy  // Enemy를 상속받음
{
public:
	RadScorpion();
	RadScorpion(const RadScorpion &ref);
	~RadScorpion();  // 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함
	RadScorpion& operator=(const RadScorpion &ref);

	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	// Enemy의 takeDamage처럼 동작하지않고 RadScorpion에서 함수를 재정의함
	virtual void takeDamage(int damage);
};

#endif 