#include "info.hpp"

void    info::inputInfo(void)
{
    for (int i=0; i<11; i++)
    {
        std::cout<<cate[i]<<" : ";
        std::getline(std::cin, content[i]);  // 한줄(띄어쓰기 포함)을 다읽기 위해 cin대신 getline 사용
    }
}

void    info::previewInfo(void)
{
    std::string str[3];

    for(int i=0; i<3; i++)
    {
        str[i] = content[i].substr(0, 10);  // 처음부터 10글자만 자르기
        if (content[i].length() >= 10)  // 10글자 이상이면
            str[i][9] = '.';  // 마지막 문자를 .로 바꿔주기
        else  // 10글자 미만이면
            str[i].append(10-content[i].length(), ' ');  // 그 뒤의문자를 공백으로 채워주기
        std::cout<<str[i];
        if (i != 2)
            std::cout<<'|';  // 마지막에는 |를 출력하지 않음
    }
    std::cout<<'\n';
}

void    info::viewInfo(void)
{
    std::cout<<"\n-------------------------------------------\n";
    for(int i=0; i<11; i++)
        std::cout<<cate[i]<<" : "<<content[i]<<'\n';
    std::cin.ignore();  // 버퍼에 남아있는 개행 제거
}

std::string info::cate[11] = 
{
    "First Name", "Last Name", "Nickname",
    "Login", "Postal Address", "Email Address",
    "Phone Number", "Birthday Rate", "Favorite Meal",
    "Underwear Color", "Darkest Secret"
};