#include "Squad.hpp"

// 기본 생성자
Squad::Squad() : count(0), units(nullptr)
{

}

// 생성자
Squad::Squad(Squad const &other): count(0), units(nullptr)
{
	for (int i = 0; i < other.getCount(); i++)  // 인자의 getCount 만큼 반복
		this->push(other.getUnit(i)->clone());  // 클론된 유닛 복제
}

// 소멸자
// 가지고있는 units 메모리 모두 해제
Squad::~Squad()
{
	if (this->units)
	{
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
	}
}

// 대입 연산자 오버로딩
Squad &Squad::operator=(Squad const &other)
{
	// 이미 존재하면, 지우고 시작하기
	if (this->units)
	{
		// std::cout<<"delete!\n";
		for (int i = 0; i < this->count; i++)
			delete this->units[i];
		delete this->units;
		this->units = nullptr;
	}

	// 참조자만 복사하는 얕은복사가아닌 객체 자체를 복사하는 깊은 복사를함 
	this->count = 0;
	for (int i = 0; i < other.getCount(); i++)
		this->push(other.getUnit(i)->clone());
	return (*this);
}

// unit 개수인 count 복사
int Squad::getCount(void) const
{
	return (count);
}

// 인덱스를 참고하여 unit을 반환
ISpaceMarine* Squad::getUnit(int index) const
{
	// 개수가 0개거나 이상한 인덱스 참고시 
	if (!count || index<0 || count<=index)
		return (nullptr);
	return (units[index]);
}

int Squad::push(ISpaceMarine *unit)
{
	if (this->units)
	{
		// 이미 들어있는 unit이 들어오면 아무처리를 하지않고 반환됨
		for (int i = 0; i < this->count; i++)
			if (this->units[i] == unit)
				return (this->count);
		
		ISpaceMarine **cpy = new ISpaceMarine*[this->count + 1];
		for (int i = 0; i < this->count; i++)
			cpy[i] = this->units[i];  // 전에있었던 units 복사
		delete[] this->units;  // 기존의 units 지우기
		this->units = cpy;
		this->units[this->count] = unit;  // 새로들어온 unit 추가
		this->count++;  // 개수 증가
	}

	// units에 아무것도 없을때
	else
	{
		this->units = new ISpaceMarine*[1];
		this->units[0] = unit;
		this->count = 1;
	}
	return (this->count);
}
