#include "ScavTrap.hpp"

// 기본생성자
// ClapTrap의 기본생성자가 호출되고 ScavTrap() 기본생성자가 호출됨
ScavTrap::ScavTrap() : ClapTrap()
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
// ClapTrap의 이름을 인자로 받는 생성자가 호출되고 ScavTrap 생성자가 호출됨
ScavTrap::ScavTrap(std::string name): ClapTrap(name)
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



// 랜덤으로 challenge를 하는 함수
void            ScavTrap::challengeNewcomer(void)
{
	srand(clock());  // 난수 사용을위해 쓰는 함수

	std::string	chall[5] =
	{
		"You have to get up at 7 am!",
		"You shouldn't rest even on weekends!",
		"You have to study English every day!",
		"Reduce the time you spend watching YouTube!",
		"You should exercise every day!"
	};
	int idx = rand()%5;  // 0 ~ 4 중 난수
	std::cout<<'['<<name<<"] : "<<chall[idx]<<'\n';
}