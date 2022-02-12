#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	Bureaucrat& operator=(const Bureaucrat& ref);
	virtual ~Bureaucrat();

	std::string	getName() const;
	int			getGrade() const;
	void		upGrade();
	void		downGrade();

	class GradeTooHighException : public std::exception  // std::exception 클래스를 상속받음
	{
	public:
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception  // std::exception 클래스를 상속받음
	{
	public:
		virtual const char* what() const throw();
	};
};

// Bureaucrat 객체를 cout으로 출력하기위해 <<연산자 오버로딩을 해줌
std::ostream&   operator<<(std::ostream &os, const Bureaucrat &ref);

#endif