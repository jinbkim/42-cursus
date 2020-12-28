#ifndef MAIN
# define MAIN
# define SIZE   3

# include <iostream>
# include <string>
# include <iomanip>  // setw



class   info
{
private:
    std::string content[11];
    static std::string cate[11];  // 쉽게 초기화 시키기위해 static 변수로 선언

public:
    void    inputInfo(void);  // 정보 입력
    void    previewInfo(void);  // 정보 미리보기
    void    viewInfo(void);  // 정보 출력
};

class   phoneBook
{
private:
    int     num;  // 정보 개수
    info    contact[SIZE];  // 정보 배열

public:
    phoneBook(void);  // 클래스 생성자
    void    addContact(void);  // 정보 추가
    void    searchContact(void);  // 정보 검색
};



void	print(const char *s);

#endif