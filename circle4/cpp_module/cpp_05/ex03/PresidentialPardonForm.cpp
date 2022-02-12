// 대통령을 탄핵하는 클래스

#include "PresidentialPardonForm.hpp"

// 생성자
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon", 25, 5), _target(target)
{
}

// 복사 생성자
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) : Form(ref), _target(ref._target)
{
}

// 대입연산자 오버로딩
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
    if (this == &ref)  // 똑같은게 들어오면
        return (*this);  // 그냥 자기자신 반환
    Form::operator=(ref);
    return (*this);
}

// 소멸자
PresidentialPardonForm::~PresidentialPardonForm()
{
}

// 대통령을 탄핵하는 함수
void    PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << _target << " has been pardoned by Zafod Beeblebrox." << '\n';
}