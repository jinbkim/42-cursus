// 생성자와 소멸자와 new와 delete를 사용해보는 과제
// 힙에 메모리가 할당되는 ponyOnTheHeap 만들기 (동적할당 new, delete) (c에서 malloc과 free랑 비슷)
// 스택에 메모리가 한달되는 ponyOnTheStack 만들기 (정적할당)
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