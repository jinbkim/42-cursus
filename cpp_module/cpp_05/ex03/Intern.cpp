#include "Intern.hpp"

// 기본 생성자
Intern::Intern()
{
}

// 복사 생성자
Intern::Intern(const Intern& ref)
{
    *this = ref;
}

// 대입연산자 오버로딩
Intern& Intern::operator=(const Intern& ref)
{
    if (this == &ref)
        return (*this);
    return (*this);
}

// 소멸자
Intern::~Intern()
{
}

Form*   Intern::makeForm(std::string formName, std::string target)
{
    std::string targets[3] = 
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

	// 크기가 3인 포인터배열로 일단 존재하는 form객체의 주소값을 담음
    Form       *forms[3];
    forms[0] = new ShrubberyCreationForm(target);
    forms[1] = new RobotomyRequestForm(target);
    forms[2] = new PresidentialPardonForm(target);

	Form       *result = 0;

	// 여기서 사용하는 객체를 고를때 if / else if / else if / else(제대로 된값이 아닐때) 처럼 못생기게 하지말아야함
	// 그렇게 하지않고 반복문을 돌림
    for (int i = 0; i < 3; i++)
    {
        if (formName == targets[i])  // 필요한 객체만 살려둠
        {
            std::cout << "Intern creates " << formName << " form." << '\n';
            result = forms[i];
            continue;
        }
        delete forms[i];  // 필요없는 객체 지움
    }
    if (result)  // formName이 제대로 된게 들어왔으면
        return (result);
	else  // formName이 제대로 된게 안들어왔으면
    	throw Intern::InvalidTypeException();  // 예외처리
    return nullptr;
}

// std::exception class의 what 함수를 오버라이딩 하여 예외처리 함수를 내맘대로 만듬
const char* Intern::InvalidTypeException::what() const throw()
{
    return "InternExeption: Invalid Type";
}