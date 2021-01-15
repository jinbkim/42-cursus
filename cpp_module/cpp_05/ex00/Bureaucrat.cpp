#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (150 < grade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
	*this = other;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &other)
{
	this->grade = other.grade;
	return (*this);
}



const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "BureaucratException: Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "BureaucratException: Grade is too low";
}



std::string const	Bureaucrat::getName() const
{
	return (name);
}

int					Bureaucrat::getGrade() const
{
	return (grade);
}

void	 			Bureaucrat::decrementGrade()
{
	--(this->grade);
	if (this->grade < 1)
		throw GradeTooLowException();
}

void	 Bureaucrat::incrementGrade()
{
	++this->grade;
	if (this->grade > 150)
		throw GradeTooHighException();
}

std::ostream	&operator<<(std::ostream &os, Bureaucrat const &b)
{
	os<<b.getName()<<", bureaucrat grade "<<b.getGrade()<<'\n';
	return (os);
}