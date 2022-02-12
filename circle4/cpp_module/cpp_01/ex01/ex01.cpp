// 주어진 함수를 수정하여 메모리해제를 하는 문제
// delete를 해줘서 메모리를 해제시킴

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