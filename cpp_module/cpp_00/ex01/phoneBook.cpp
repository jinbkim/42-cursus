#include "main.hpp"

phoneBook::phoneBook(void) : num(0)  // num을 0으로 초기화
{

}

void    phoneBook::addContact(void)
{
    if (num == SIZE)
        print("PhoneBook is full!");
    else
        contact[num++].inputInfo();
}

void    phoneBook::searchContact(void)
{
    int     idx;

    std::cout<<"     index|first name| last name|  nickname\n";
	std::cout<<"-------------------------------------------\n";
    for(int i=0; i<num; i++)
    {
        std::cout<<std::setw(10);  // 10칸으로 간격유지
        std::cout<<i<<'|';
        contact[i].previewInfo();  // 3개만 미리보기
    }
	std::cout<<"\nselect index : ";
    std::cin>>idx;
    if (idx<0 || num<=idx || std::cin.fail())  // 입력이 음수거나 범위에 없거나 정수가 아니면
    {
		print("wrong index!");
		std::cin.clear();  // cin.fail()가 참일때 내부상태 플래그를 초기화시켜서  cin이 올바른 동작을 하게함
		std::cin.ignore();  // 버퍼에 남아있는 값 제거
    }
    else
        contact[idx].viewInfo();  // 정보 보기
}