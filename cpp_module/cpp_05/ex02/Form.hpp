#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_executeGrade;
	Form();

public:
	Form(std::string name, int signGrade, int executeGrade);
	Form(const Form& ref);
	~Form();
	Form& operator=(const Form& ref);

	std::string		getName() const;
	bool			getSigned() const;
	int         	getSignGrade() const;
	int         	getExecuteGrade() const;
	void        	beSigned(Bureaucrat& ref);

	// Form클래스의 execute함수를 순수 가상함수로 선언함으로써 이를 상속받은 클래스에서 execute함수를 재정의함
	virtual void    execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class NotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
};

std::ostream&   operator<<(std::ostream &os, const Form &ref);

#endif