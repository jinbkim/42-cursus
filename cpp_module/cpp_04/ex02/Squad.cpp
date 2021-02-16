#include "Squad.hpp"

// 기본 생성자
Squad::Squad()
{
    num = 0;
    head = NULL;
}

// 복사 생성자
Squad::Squad(const Squad &ref)
{
    *this = ref;
}

// 소멸자
Squad::~Squad()
{
    t_list  *cur = head;
    t_list  *next;
	int		i=-1;

	// 가지고있는 unit들 메모리 모두 해제
	std::cout<<"22222\n";
	std::cout<<"num : "<<num<<'\n';
    while (++i < num)
    {
		std::cout<<"hi!\n";
        next = cur->next;
        delete cur->unit;
        delete cur;
        cur = next;
    }
}

// 대입연산자 오버로딩
Squad& Squad::operator=(const Squad &ref)
{
	// std::cout<<"===========\n";
    t_list  *cur;
	t_list	*next;

    cur = head;
	// 반환받는 값에 원래 존재하던 값은 모두 지워져야함
	if (!num)
	{
		while (cur)
		{
			next = cur->next;
			delete cur->unit;
			delete cur;
			cur = next;
		}
	}
	// 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 
    for (int i = 0 ; i < ref.getCount(); i++)
        push(ref.getUnit(i));
    return (*this);
}



// num을 반환하는 함수
int				Squad::getCount() const
{
    return (num);
}

// 인덱스를 받아 unit을 반환하는 함수
ISpaceMarine*	Squad::getUnit(int idx) const
{
    t_list *cur;

    if (getCount() <= idx)
        return (NULL);   
    cur = head;
    for(int i = 0 ; i < idx ; i++)
        cur = cur->next;
    return (cur->unit);
}

// 연결리스트의 맨끝에 인자로받은 unit을 추가하는 함수
int             Squad::push(ISpaceMarine* marine)
{
    t_list  *cur;
    t_list  *newMarine;


    newMarine = new t_list;
    newMarine->unit = marine;
    newMarine->next = NULL;
    cur = head;
    if (!cur)
    {
        head = newMarine;
		head->next = NULL;
        return (++num);
    }
	std::cout<<"======\n";
	int i=0;
    while (cur->next)
	{
		std::cout<<"i : "<<++i<<'\n';
        cur = cur->next;
	}
    cur->next = newMarine;
    return (++num);
}