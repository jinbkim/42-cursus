#include "FragTrap.hpp"

// 기본생성자
// ClapTrap의 기본생성자가 호출되고 FragTrap() 기본생성자가 호출됨
FragTrap::FragTrap() : ClapTrap()
{
    name = "unknown";
    hp = 100;
    maxHp = 100;
    ep = 100;
    maxEp = 100;
    level = 1;
    meleeDam = 30;
    rangedDam = 20;
    armor = 5;
	std::cout<<name<<" player joined the game!\n"; 
}

// 이름을 인자로 받는 생성자
// ClapTrap의 이름을 인자로 받는 생성자가 호출되고 FragTrap 생성자가 호출됨
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
    hp = 100;
    maxHp = 100;
    ep = 100;
    maxEp = 100;
    level = 1;
    meleeDam = 30;
    rangedDam = 20;
    armor = 5;
	std::cout<<name<<" player joined the game!\n"; 
}

// 복사생성자
FragTrap::FragTrap(const FragTrap &ref)
{
    *this = ref;
	std::cout<<name<<" player joined the game!\n"; 
}

// 대입 연산자 오버로딩
FragTrap& FragTrap::operator=(const FragTrap & ref)
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
FragTrap::~FragTrap()
{
    std::cout << name << " player left the game!\n";
}



// 랜덤무기로 공격하는 함수
unsigned int	FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	srand(clock()); // 난수 사용을위해 쓰는 함수

	if (ep < 25)  // ep가 부족하면
	{
        std::cout<<name<<" is out of energy!\n";
        return (0);
	}
	ep -= 25;
	std::string	attack[] = {"fist", "wooden stick", "arrow", "pistol", "mahine gun"};
	int		damage[] = {10, 20, 30, 40, 50};  // 각 무기들의 데미지
	int		idx;
	idx = rand()%5;  // 0 ~ 4 중 난수
	std::cout<<name<<" attacks "<<target<< " with "<< attack[idx] 
	<< " causing "<< damage[idx] << " points of damage!\n";
	return (damage[idx]);  // 인자로 들어오는 객체가 받는 랸덤데미지를 반환
}