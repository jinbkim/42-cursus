#include "Pony.hpp"

Pony::Pony(std::string name)  // 생성자
{
    this->name = name;
    std::cout<<this->name<<" pony constructor is called!\n";
}

Pony::~Pony()  // 소멸자
{
    std::cout<<this->name<<" pony destructor is called!\n";
}