#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
protected:
	std::string	name;
	std::string	title;

public:
    Sorcerer();  // 선언만함
	Sorcerer(std::string name, std::string title);
    Sorcerer(const Sorcerer &ref);
    ~Sorcerer();
    Sorcerer& operator=(const Sorcerer &ref);

	std::string getName() const;
	std::string getTitle() const;
	void		polymorph(Victim const &ref) const;
};

std::ostream& operator<<(std::ostream &os, const Sorcerer &ref);

#endif