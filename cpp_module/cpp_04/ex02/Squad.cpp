#include "Squad.hpp"

Squad::Squad()
{
    num = 0;
    head = NULL;
}

Squad::Squad(const Squad &ref)
{
    *this = ref;
}

Squad::~Squad()
{
    t_list  *cur = head;
    t_list  *next;

	// 가지고있는 unit들 메모리 해제
    while (cur)
    {
        next = cur->next;
        delete cur->unit;
        delete cur;
        cur = next;
    }
}

Squad& Squad::operator=(const Squad &ref)
{
	std::cout<<"hi!\n";
    t_list  *cur;
    t_list  *next;

    cur = head;
	// 반환받는 값에 존재하던 값은 모두 지워져야함
    while (cur)
    {
        next = cur->next;
        delete cur->unit;
        delete cur;
        cur = next;
    }
    this->~Squad();
	// 참조자값만 복사하는것이 아닌 객체 자체를 복사하는 깊은 복사를함 
    for (int i = 0 ; i < ref.getCount(); i++)
        push(ref.getUnit(i));
    return (*this);
}



int				Squad::getCount() const
{
    return (num);
}

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
        return (++num);
    }
    while (cur->next)
        cur = cur->next;
    cur->next = newMarine;
    return (++num);
}