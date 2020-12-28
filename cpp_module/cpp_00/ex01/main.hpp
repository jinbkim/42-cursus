#ifndef MAIN
# define MAIN
# define SIZE   3

# include <iostream>
# include <string>
# include <iomanip>



class   info
{
private:
    std::string content[11];
    static std::string cate[11];  // 쉽게 초기화 시키기위해 static 변수로 선언

public:
    void    initInfo(void);
    void    previewInfo(void);
    void    viewInfo(void);
};

class   phoneBook
{
private:
    int     num;
    info    contact[SIZE];

public:
    phoneBook(void);
    void    addContact(void);
    void    searchContact(void);
};



void	print(const char *s);

#endif