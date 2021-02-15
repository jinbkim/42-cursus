#include "ScavTrap.hpp"

// 기본생성자
// 이름외에 pdf에서 넣으란값을 넣음
// FragTrap와 기본값이 조금다름
ScavTrap::ScavTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 50;
    maxEp = 50;
    level = 1;
    meleeDam = 20;
    rangedDam = 15;
    armor = 3;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

// 이름을 인자로 받는 생성자
// 이름외에 pdf에서 넣으란값을 넣음
// FragTrap와 기본값이 조금다름
ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 50;
    maxEp = 50;
    level = 1;
    meleeDam = 20;
    rangedDam = 15;
    armor = 3;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

// 복사생성자
ScavTrap::ScavTrap(const ScavTrap &ref)
{
    *this = ref;
	std::cout<<'['<<name<<"] player joined the game!\n"; 
}

// 대입 연산자 오버로딩
ScavTrap& ScavTrap::operator=(const ScavTrap & ref)
{
	name = ref.name;
    hp = ref.hp;
    maxHp = ref.maxHp;
    ep = ref.ep;
    maxEp = ref.maxEp;
    level = ref.level;
    meleeDam = ref.meleeDam;
    rangedDam = ref.rangedDam;
    armor = ref.armor;
    return (*this);
}

// 소멸자
ScavTrap::~ScavTrap()
{
    std::cout<<'['<<name<<"] player left the game!\n";
}

// 공격했다고 말하고, 해당객체의 angedDam를 반환하는 함수
unsigned int    ScavTrap::rangedAttack(std::string const &target)
{
	std::cout<<'['<<name<<"] funny attacks "<<target<<" at range, causing " 
	<<rangedDam<<" points of damage!\n";
    return (rangedDam);
}

// 공격했다고 말하고, 해당객체의 meleeDam를 반환하는 함수
unsigned int    ScavTrap::meleeAttack(std::string const &target)
{
    std::cout<<'['<<name<<"] funny attacks "<<target<<" at melee, causing " 
	<<meleeDam<<" points of damage!\n";
    return (meleeDam);
}

// 공격받은 량을 인자로 받아서 해당객체가 데미지를 받는 함수
void    ScavTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)  // 이미 죽었으면
	{
		std::cout<<'['<<name<<"] already dead!\n";
		return ;
	}
	int damage = amount-armor;

	if (damage < 0)  // 공격을 받았는데 방어력이 더크면
		damage = 0;  // 데미지를 안받음
	hp -= damage;
	std::cout<<'['<<name<<"] takes "<< damage<<" point(s) of funny damage!\n";
	if (hp <= 0)  // 피가 0이하면
	{
		hp = 0;
		std::cout<<'['<<name<<"] dead!\n";
	}
}

// 인자만큼 해당객체가 회복하는 함수
void    ScavTrap::beRepaired(unsigned int amount)
{
	hp += amount;  // hp 회복
	ep += amount;  // mp 회복
	if (maxHp < hp)  // hp가 최대 hp보다 크면
		hp = maxHp;  // 최대 hp값으로 맞춤. hp limit
	if (maxEp < ep)  // ep가 최대 ep보다 크면
		ep = maxEp;  // 최대 ep로 맞춤. ep limit
	std::cout<<'['<<name<<"] repaired "<<amount<<" point(s)! of hit and energy!\n";
}

// 상태를 보여주는 함수
void	ScavTrap::show_state(void)
{
	std::cout<<"------------------\n";
	std::cout<<"name : "<<'['<<name<<"]\n";
	std::cout<<"hp : "<<hp<<'\n';
	std::cout<<"ep : "<<ep<<'\n';
	std::cout<<"------------------\n";
}

// 랜덤으로 challenge를 하는 함수
void            ScavTrap::challengeNewcomer(void)
{
	srand(clock());  // 난수 사용을위해 쓰는 함수

	std::string	chall[5] =
	{
		"You have to get up funny at 7 am!",
		"You shouldn't rest funny even on weekends!",
		"You have to study funny English every day!",
		"Reduce the time you spend funny watching YouTube!",
		"You should funny exercise every day!"
	};
	int idx = rand()%5;  // 0 ~ 4 중 난수
	std::cout<<'['<<name<<"] : "<<chall[idx]<<'\n';
}