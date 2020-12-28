// 힙에 할당되는 클래스와 스택에 할당되는 클래스를 만드는 함수만들기
// 함수가 끝나면 만들어진 객체가 소멸됨을 보여줘야함

#include "Pony.hpp"

void    ponyOnTheHeap(const char *str)
{
    Pony *pony = new Pony(str);  // 동적할당으로 포니객체 생성
    delete pony;  // 동적할당 해제
}

void    ponyOnTheStack(const char *str)
{
    Pony pony(str);  // 정적할당으로 포니객체 생성
}

int     main(void)
{
    std::cout<<"\n----- ponyOnTheHeap -----\n";
    ponyOnTheHeap("AAA");
    ponyOnTheHeap("BBB");

    std::cout<<"\n----- ponyOnTheStack -----\n";
    ponyOnTheStack("CCC");
    ponyOnTheStack("DDD");

    return (0);
}