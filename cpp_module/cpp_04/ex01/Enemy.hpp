#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
protected:
	int			HP;
	std::string	type;

public:
	Enemy();
	Enemy(int hp, std::string const &type);
	Enemy(const Enemy &ref);
	//하위 클래스의 객체를 상위 클래스의 포인터로 가리킬 때, 가상 소멸자를 만들어야함
	//가상 소멸자를 만들지 않으면 상위 클래스의 포인터를 delete 할때, 하위 클래스의 소멸자가 호출되지 않음
	virtual ~Enemy();
	Enemy	&operator=(const Enemy &ref);

	std::string     getType() const;
	int             getHP() const;
	// 가상함수 : 상위 클래스 내에서 선언되어 하위 클래스에 의해 재정의 되는 멤버 함수
	virtual void	takeDamage(int);
};

#endif