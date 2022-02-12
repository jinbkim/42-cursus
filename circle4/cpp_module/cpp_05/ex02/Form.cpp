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
	// 자기와 같은 게 들어오면
    if (this == &ref)
        return (*this);
    if (_signGrade < 1 || _executeGrade < 1)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 1등급보다 높으면 
        throw Form::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
	else if (_signGrade > 150 || _executeGrade > 150)  // 서명에 필요한 등급 또는 실행에 필요한 등급이 150등급보다 낮으면 
        throw Form::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
    return (*this);
}

// 소멸자
Form::~Form()
{
}

// Name을 반환하는 함수
std::string         Form::getName() const
{
    return (_name);
}

// Signed을 반환하는 함수
bool                Form::getSigned() const
{
    return (_signed);
}

// SignGrade를 반환하는 함수
int                 Form::getSignGrade() const
{
    return (_signGrade);
}

// ExecuteGrade를 반환하는 함수
int                 Form::getExecuteGrade() const
{
    return (_executeGrade);
}

// Signed을 해주는 함수
void                Form::beSigned(Bureaucrat& ref)
{
    if (_signGrade > ref.getGrade())  // 객체 인자의 등급이 기준이되는 signGrade 보다 높으면
        _signed = true;  // Signed을 해줌
    else  // 객체 인자의 등급이 기준이되는 signGrade 보다 낮으면
        throw Form::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}

// execute를 해주는 함수
void                Form::execute(Bureaucrat const & executor) const
{
    if (_signed == false)  // sign이 안되있으면 
        throw Form::NotSignedException();  // NotSignedExceptionn클래스를 catch로 던짐
    else if (executor.getGrade() > _executeGrade)  // 객체 인자의 등급이 기준이되는 executeGrade 보다 낮으면
        throw Form::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}



// std::exception class의 what 함수를 오버라이딩 하여 예외처리 함수를 내맘대로 만듬
const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Grade too High");
}

// std::exception class의 what 함수를 오버라이딩 하여 예외처리 함수를 내맘대로 만듬
const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Grade too Low");
}

// std::exception class의 what 함수를 오버라이딩 하여 예외처리 함수를 내맘대로 만듬
const char* Form::NotSignedException::what() const throw()
{
	return ("FormException: Not Signed");
}

// Form 객체를 cout으로 출력하기위해 <<연산자 오버로딩을 해줌
std::ostream&   operator<<(std::ostream &os, const Form &ref)
{
    return (os << ref.getName() << 
        ", sign status " << ref.getSigned() << 
        ", sign grade " << ref.getSignGrade() << 
        ", execute grade " << ref.getExecuteGrade() << std::endl); 
}