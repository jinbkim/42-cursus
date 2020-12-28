#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>
#include <string>

class   Pony
{
private:
    std::string name;
public:
    Pony(std::string name);  // 생성자
    ~Pony();  // 소멸자
};

#endif