// 주어진 함수에 메모리해제를 하는 문제

#include <iostream>
#include <string>

void    memoryLeak()
{
    std::string* panther = new std::string("String panther");
    std::cout<<*panther<< std::endl;
    delete panther;
}

int     main(void)
{
    memoryLeak();
}