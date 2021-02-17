#include "Form.hpp"
#include "Bureaucrat.hpp"

// name, signGrade, executeGrade로 인자로 받는 생성자
Form::Form(std::string name, int signGrade, int executeGrade) :_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (_signGrade < 1 || _executeGrade < 1)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 1등급보다 높으면 
        throw Form::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
	else if (_signGrade > 150 || _executeGrade > 150)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 150등급보다 낮으면 
        throw Form::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}

// 복사 생성자
Form::Form(const Form& ref) : _name(ref.getName()), _signed(getSigned()), _signGrade(ref.getSignGrade()), _executeGrade(ref.getExecuteGrade())
{
    if (_signGrade < 1 || _executeGrade < 1)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 1등급보다 높으면 
        throw Form::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
	else if (_signGrade > 150 || _executeGrade > 150)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 150등급보다 낮으면 
        throw Form::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}

// 대입연산자 오버로딩
Form& Form::operator=(const Form& ref)
{
    if (this == &ref)
        return (*this);
    _signed = ref.getSigned();
    if (_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
    return (*this);
}

Form::~Form()
{
}

std::string         Form::getName() const
{
    return (_name);
}

bool                Form::getSigned() const
{
    return (_signed);
}

int                 Form::getSignGrade() const
{
    return (_signGrade);
}

int                 Form::getExecuteGrade() const
{
    return (_executeGrade);
}

void                Form::beSigned(Bureaucrat& ref)
{
    if (_signGrade > ref.getGrade())
        _signed = true;
    else    
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

std::ostream&   operator<<(std::ostream &os, const Form &ref)
{
    return (os << ref.getName() << 
        ", sign status " << ref.getSigned() << 
        ", sign grade " << ref.getSignGrade() << 
        ", execute grade " << ref.getExecuteGrade() << std::endl); 
}
