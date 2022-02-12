#include "SuperTrap.hpp"

// 기본생성자
SuperTrap::SuperTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 20;
    armor = 5;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";
}

// 이름을 인자로 받는 생성자
SuperTrap::SuperTrap(std::string name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 20;
    armor = 5;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";	
}

// 복사생성자
SuperTrap::SuperTrap(const SuperTrap & ref)
{
    *this = ref;
	std::cout<<"[SUPER] "<<name<<" player joined the game!\n";	
}

// 대입 연산자 오버로딩
SuperTrap& SuperTrap::operator=(const SuperTrap & ref)
{
    this->name = ref.name;
	hp = ref.hp;
    maxHp = ref.maxHp;
    ep = ref.maxHp;
    maxEp = ref.maxEp;
    level = ref.level;
    meleeDam = ref.rangedDam;
    rangedDam = ref.rangedDam;
    armor = ref.armor;
    return (*this);    
}

// 소멸자
SuperTrap::~SuperTrap()
{
	std::cout<<"[SUPER] "<<name<<" player left the game!\n";
}

// SuperTrap의 rangedAttack은 FragTrap의 rangedAttack를 사용
unsigned int    SuperTrap::rangedAttack(std::string const &target)
{
    return (FragTrap::rangedAttack(target));
}

// SuperTrap의 meleeAttack은 NinjaTrap의 meleeAttack를 사용
unsigned int    SuperTrap::meleeAttack(std::string const &target)
{
    return (NinjaTrap::meleeAttack(target));
}