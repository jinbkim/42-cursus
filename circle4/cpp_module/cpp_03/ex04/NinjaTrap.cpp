#include "NinjaTrap.hpp"

// 기본생성자
// ClapTrap의 기본생성자가 호출되고 NinjaTrap() 기본생성자가 호출됨
NinjaTrap::NinjaTrap() : ClapTrap() 
{
    name = "unknown";
    hp = 60;
    maxHp = 60;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 5;
    armor = 0;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

// 이름을 인자로 받는 생성자
// ClapTrap의 이름을 인자로 받는 생성자가 호출되고 NinjaTrap 생성자가 호출됨
NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
    hp = 60;
    maxHp = 60;
    ep = 120;
    maxEp = 120;
    level = 1;
    meleeDam = 60;
    rangedDam = 5;
    armor = 0;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

// 복사생성자
NinjaTrap::NinjaTrap(const NinjaTrap &ref)
{
    *this = ref;
	std::cout<<"[NINJA] "<<name<<" player joined the game!\n";
}

// 대입 연산자 오버로딩
NinjaTrap& NinjaTrap::operator=(const NinjaTrap &ref)
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
NinjaTrap::~NinjaTrap()
{
    std::cout<<"[NINJA] "<<name<<" player left the game!\n";
}


// special attack인 ninjaShoebox 함수 만들기
// 함수의 인자를 각각 다른 클래스를 참조자로 받음
// 각각 다른 클래스를 참조자로 인자만 다른 ninjaShoebox 함수를 오버로딩 하여 4개 만들기
// 각각 다른 동작을 함
// 자유롭게 만들기

void   NinjaTrap::ninjaShoebox(const FragTrap & ref)
{
    std::cout<<"[NINJA->FragTrap] "<<name<<" funny attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const ScavTrap & ref)
{
    std::cout<<"[NINJA->ScavTrap] "<<name<<" funny attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const NinjaTrap & ref)
{
    std::cout<<"[NINJA->NinjaTrap] "<<name<<" funny attacks "<<ref.name<<'\n';
}

void   NinjaTrap::ninjaShoebox(const ClapTrap & ref)
{
    std::cout<<"[NINJA->ClapTrap] "<<name<<" funny attacks "<<ref.name<<'\n';
}      