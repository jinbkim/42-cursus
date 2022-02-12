#ifndef INFO_HPP
# define INFO_HPP

# include <iostream>
# include <string>

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

#endif