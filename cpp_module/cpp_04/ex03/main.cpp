// interface class에 대해 알아가는 문제
// interface class를 사용하는 이유는 여러이유가 있지만 그중 하나는 이 클래스를 보면서 이 클래스를 상속받는 클래스들은 뭐를 하겠구나 한눈에 알수있음
// 즉 코드의 가독성때문
// interface class : 가상소멸자와 가상함수로만 이루어진 클래스
// ICharacter, IMateriaSource는 interface class

// abstract class : 하나 이상의 순수 가상함수가 선언된 클래스
// 순수 가상 함수 :선언만 있고 함수의 몸체가 정의되지 않은 가상 함수
// AMateria는 abstract class

// Character 대입연산자 오버로딩할때 이미 Materia가 존재하면 다지우고 시작함
// *this = other 이런식으로 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 

// ICharacter를 상속받은 클래스 : Character

// AMateria를 상속받은 클래스 : Cure, Ice 

// IMateriaSource를 상속받은 클래스 : MateriaSource

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
