#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

// abstract class : 하나 이상의 순수 가상함수가 선언된 클래스
// 순수 가상 함수 :선언만 있고 함수의 몸체가 정의되지 않은 가상 함수
class AMateria
{
protected:
	std::string		_type;
	unsigned int	_xp;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &other);
	virtual ~AMateria();
	AMateria& operator=(AMateria const &other);

	std::string const	&getType() const;
	unsigned int		getXP() const;
	virtual AMateria	*clone() const = 0;  // 순수 가상함수
	virtual void		use(ICharacter &target);
};

#endif