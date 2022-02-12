// 로봇토미에게 부탁하는 클래스

#include "RobotomyRequestForm.hpp"

// 생성자
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request", 72, 45), _target(target)
{
}

// 복사생성자
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref) : Form(ref), _target(ref._target)
{
}

// 대입 연산자
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
    if (this == &ref)
        return (*this);
    Form::operator=(ref);
    return (*this);
}

// 소멸자
RobotomyRequestForm::~RobotomyRequestForm()
{
}

// 로봇토미에게 부탁하는 함수
void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << "* rizzz...bzzz... *" << std::endl;
    int ret = rand();  // 랜덤 변수
    if(ret % 2)  // 랜덤변수가 홀수이면 (50% 확률)
        std::cout << _target << " has been robotomized succesfully." << std::endl;
    else  // 랜덤변수가 짝수이면 (50% 확률)
        std::cout << _target << " robotomization has failed." << std::endl;
}