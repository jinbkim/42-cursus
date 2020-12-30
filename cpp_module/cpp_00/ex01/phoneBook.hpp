#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "info.hpp"
# include <iomanip>  // setw
# define SIZE   3

class   phoneBook
{
private:
    int     num;  // 정보 개수
    info    contact[SIZE];  // 정보 배열

public:
    phoneBook(void);  // 클래스 생성자
    void    addContact(void);  // 정보 추가
    void	searchContact(void);  // 정보 검색
};

void	print(const char *s);

#endif