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
	virtual ~AWeapon();
	AWeapon& operator=(const AWeapon &ref);

	std::string     getName() const;
	int             getAPCost() const;
	int             getDamage() const;
	virtual void    attack() const = 0;
};

#endif