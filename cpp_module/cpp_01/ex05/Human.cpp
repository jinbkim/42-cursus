#include "Human.hpp"

const std::string	Human::identify() const
{
	std::cout<<"===== include human.hpp =====\n";
    return (brain.identify());
}

// 브레인을 반환하는 함수
const Brain&		Human::getBrain() const
{
    const Brain& ref=brain;

    return (ref);
}