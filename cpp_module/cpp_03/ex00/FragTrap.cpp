#include "FragTrap.hpp"

// 기본생성자
// 이름외에 pdf에서 넣으란값을 넣음
FragTrap::FragTrap()
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
// 이름외에 pdf에서 넣으란값을 넣음
FragTrap::FragTrap(std::string name)
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

// 공격했다고 말하고, 해당객체의 angedDam를 반환하는 함수
unsigned int    FragTrap::rangedAttack(std::string const &target)
{
	std::cout<<name<< " funny attacks "<<target<<" at range, causing " 
	<<rangedDam<<" points of damage!\n";
    return (rangedDam);
}

// 공격했다고 말하고, 해당객체의 meleeDam를 반환하는 함수
unsigned int    FragTrap::meleeAttack(std::string const &target)
{
    std::cout<<name<< " funny attacks "<<target<<" at melee, causing " 
	<<meleeDam<<" points of damage!\n";
    return (meleeDam);
}

// 공격받은 량을 인자로 받아서 해당객체가 데미지를 받는 함수
void    FragTrap::takeDamage(unsigned int amount)
{
	if (hp == 0)  // 이미 죽었으면
	{
		std::cout<<name<<" already dead!\n";
		return ;
	}
	int damage = amount-armor;

	if (damage < 0)  // 공격을 받았는데 방어력이 더크면
		damage = 0;  // 데미지를 안받음
	hp -= damage;
	std::cout<<name<<" takes "<< damage<<" point(s) of funny damage!\n";
	if (hp <= 0)  // 피가 0이하면
	{
		hp = 0;
		std::cout<<name<<" dead!\n";
	}
}

// 인자만큼 해당객체가 회복하는 함수
void    FragTrap::beRepaired(unsigned int amount)
{
	hp += amount;  // hp 회복
	ep += amount;  // mp 회복
	if (maxHp < hp)  // hp가 최대 hp보다 크면
		hp = maxHp;  // 최대 hp값으로 맞춤. hp limit
	if (maxEp < ep)  // ep가 최대 ep보다 크면
		ep = maxEp;  // 최대 ep로 맞춤. ep limit
	std::cout<<name<<" repaired "<<amount<<" point(s)! of hit and energy!\n";
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
	// 무기
	std::string	attack[] = {"funny fist", "funny wooden stick", "funny arrow", "funny pistol", "funny mahine gun"};
	int		damage[] = {10, 20, 30, 40, 50};  // 각 무기들의 데미지
	int		idx;
	idx = rand()%5; // 0 ~ 4 중 난수
	std::cout<<name<<" funny attacks "<<target<< " with "<< attack[idx] 
	<< " causing "<< damage[idx] << " points of damage!\n";
	return (damage[idx]);  // 인자로 들어오는 객체가 받는 랸덤데미지를 반환
}

// 상태를 보여주는 함수
void			FragTrap::show_state(void)
{
	std::cout<<"------------------\n";
	std::cout<<"name : "<<name<<'\n';
	std::cout<<"hp : "<<hp<<'\n';
	std::cout<<"ep : "<<ep<<'\n';
	std::cout<<"------------------\n";

}