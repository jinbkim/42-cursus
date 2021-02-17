#include "Bureaucrat.hpp"
#include "Form.hpp"

// name과 grade를 인자로 받는 생성자
Bureaucrat::Bureaucrat(const std::string &name, int grade) :_name(name), _grade(grade)
{
    if (_grade < 1)  // 1등이 최고인데 1등보다 높으면
        throw Bureaucrat::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
    else if (_grade > 150)  // 150등이 꼴찌인데 150등보다 낮으면 
        throw Bureaucrat::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}

// 복사 생성자
Bureaucrat::Bureaucrat(const Bureaucrat& ref) : _name(ref.getName()), _grade(ref.getGrade())
{
    if (_grade < 1)  // 1등이 최고인데 1등보다 높으면
        throw Bureaucrat::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
    else if (_grade > 150)  // 150등이 꼴찌인데 150등보다 낮으면 
        throw Bureaucrat::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
}

// 대입연산자 오버로딩
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    if (this == &ref)  // 자기 자신이 들어오면
        return (*this);  // 그냥 자기자신 반환
    _grade = ref.getGrade();
    if (_grade < 1)  // 1등이 최고인데 1등보다 높으면
        throw Bureaucrat::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
    else if (_grade > 150)  // 150등이 꼴찌인데 150등보다 낮으면 
        throw Bureaucrat::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
    return (*this);
}

// 소멸자
Bureaucrat::~Bureaucrat()
{

}



// Name을 반환하는 함수
std::string         Bureaucrat::getName() const
{
    return (_name);
}

// Grade를 반환하는 함수
int                 Bureaucrat::getGrade() const
{
    return (_grade);
}

// Grade를 하나 올리는 함수
void            Bureaucrat::upGrade()
{
    if (_grade <= 1)  // 1등이 최고인데 1등보다 높으면
        throw Bureaucrat::GradeTooHighException();  // GradeTooHighException클래스를 catch로 던짐
    _grade -= 1;
}

// Grade를 하나 내리는 함수
void            Bureaucrat::downGrade()
{
    if (_grade >= 150)  // 150등이 꼴찌인데 150등보다 낮으면 
        throw Bureaucrat::GradeTooLowException();  // GradeTooLowException클래스를 catch로 던짐
    _grade += 1;
}

// 
void                Bureaucrat::signForm(Form& ref)
{
    try
    {
        ref.beSigned(*this);
        std::cout << _name << " signs " << ref.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " cannot sign " << ref.getName() << " because ";
        std::cerr << e.what() << '\n';
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException: Grade too High");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException: Grade too Low");
}

std::ostream&   operator<<(std::ostream &os, const Bureaucrat &ref)
{
    return (os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << std::endl);
}
