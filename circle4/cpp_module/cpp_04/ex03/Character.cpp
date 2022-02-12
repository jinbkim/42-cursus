#include "Character.hpp"

// name을 인자로받는 생성자
Character::Character(std::string name) : _name(name), _equipped(0)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

// 복사 생성자
Character::Character(Character const &other)
{
	*this = other;
}

Character::~Character()
{
	int	i = -1;

	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
}

// 대입연산자 오버로딩
Character &Character::operator=(Character const &other)
{
	int i = -1;

	// 반환받는 값에 존재하던 값은 모두 지워져야함
	while (this->_inventory[++i])
	{
		delete _inventory[i];
		this->_inventory[i] = NULL;
	}
	this->_name = other.getName();
	i = -1;
	// 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 
	//*this = other;
	while (other._inventory[++i])
		this->equip(other._inventory[i]->clone());
	return (*this);
}

// name을 반환하는 함수
std::string const	&Character::getName() const
{
	return (this->_name);
}



// 아이템을 사용하는 함수
void	Character::equip(AMateria *m)
{
	//  아이템이 없거나  아이템을 3개이상 사용중이거나
	if (!m || 3<this->_equipped)
		return ;
	// 이미 사용중인  아이템이면 아무것도 하지않고 함수종료
	for (int i=0; i<this->_equipped; i++)
		if (this->_inventory[i] == m)
			return ;
	this->_inventory[this->_equipped++] = m;  // 아이템 추가
}

// 아이템을 빼는 함수
void	Character::unequip(int idx)
{
	// 잘못된 인덱스를 참고할 경우
	if (idx<0 || this->_equipped<=idx)
		return ;
	// 뺴는 아이템 뒤에있는 아이템을 앞으로 옮기기
	while (idx < 3)
	{
		this->_inventory[idx] = this->_inventory[idx+1];
		idx++;
	}
	this->_inventory[idx] = NULL;
	(this->_equipped)--;  // 아이템 개수 빼기
}

// 아이템을 사용하는 함수
void	Character::use(int idx, ICharacter &target)
{
	// 잘못된 인덱스를 참고할 경우
	if (idx<0 || _equipped<=idx)
		return ;
	this->_inventory[idx]->use(target);
}