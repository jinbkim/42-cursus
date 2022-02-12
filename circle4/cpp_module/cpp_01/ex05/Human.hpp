#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Brain.hpp"

class Human
{
private:
    const Brain brain;
public:
    const std::string	identify() const;
    const Brain&		getBrain() const;    
};

#endif