#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

typedef struct      s_list
{
	ISpaceMarine	*unit;
	struct s_list	*next;
}                   t_list;

class Squad: public ISquad
{
private:

	t_list	*head;
	int		num;

public:
	Squad();
	Squad(const Squad &ref);
	virtual ~Squad();
	Squad &operator=(const Squad &ref);

	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int idx) const;
	virtual int push(ISpaceMarine *marine);
};

#endif