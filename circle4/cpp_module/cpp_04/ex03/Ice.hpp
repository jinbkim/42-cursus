#ifndef Ice_HPP
# define Ice_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(Ice const &other);
	virtual ~Ice();
	Ice	&operator=(Ice const &other);

	virtual Ice		*clone() const;
	virtual void	use(ICharacter &target);
};

#endif