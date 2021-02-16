#ifndef AWEAPON_HPP
# define AWEAPON_HPP

# include <iostream>

class AWeapon
{
protected:
	std::string	name;
	int		damage;
	int		APCost;

public:
    AWeapon();
	AWeapon(std::string const &name, int apcost, int damage);
	AWeapon(const AWeapon &ref);
	//하위 클래스의 객체를 상위 클래스의 포인터로 가리킬 때, 가상 소멸자를 만들어야함
	//가상 소멸자를 만들지 않으면 상위 클래스의 포인터를 delete 할때, 하위 클래스의 소멸자가 호출되지 않음
	virtual ~AWeapon();  // 클래스에서 가상 함수를 정의할 때 소멸자도 가상함수로 만들어야 함
	AWeapon& operator=(const AWeapon &ref);

	std::string     getName() const;
	int             getAPCost() const;
	int             getDamage() const;
	virtual void    attack() const = 0;  // 순수 가상함수 : 선언만 있고 함수의 몸체가 정의되지 않은 가상 함수
};

#endif