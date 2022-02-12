#include "MateriaSource.hpp"

// 기본 생성자
MateriaSource::MateriaSource() : _count(0)
{
	for (int i = 0; i < 4; i++)
		_materia[i] = NULL;
}

// 복사 생성자
MateriaSource::MateriaSource(MateriaSource const & other)
{
	*this = other;
}

// 소멸자
MateriaSource::~MateriaSource()
{
}

// 대입연산자
MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	// 이미 존재한 materia 삭제
	// materia가 존재하지 않으면 _count가 0이라 반복문을 넘어감
	for (int i=0; i<this->_count; i++)
	{
		delete _materia[i];
		this->_materia[i] = NULL;
	}
	// Materia를 싹다 복제
	for (int i=0; i<other._count; i++)
		this->learnMateria(other._materia[i]);
	return (*this);
}



// Materia를 복제하는 함수
void		MateriaSource::learnMateria(AMateria *m)
{	
	if (3<this->_count || !m)
		return ;
	this->_materia[this->_count++] = m->clone();
}

// 인자 type과 같은 materia를 복제하는 함수
AMateria*	MateriaSource::createMateria(std::string const & type)
{
	// 들어온 인자의 materia를 발견하면 복제
	for (int i=0; i<this->_count; i++)
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	
	return (0);
}
