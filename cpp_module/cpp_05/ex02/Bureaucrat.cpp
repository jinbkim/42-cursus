/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:44:09 by yechoi            #+#    #+#             */
/*   Updated: 2021/01/24 01:25:28 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    :_name(name), _grade(grade)
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref)
    : _name(ref.getName()), _grade(ref.getGrade())
{
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& ref)
{
    if (this == &ref)
        return (*this);
    _grade = ref.getGrade();
    if (_grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (_grade > 150)
        throw Bureaucrat::GradeTooLowException();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string         Bureaucrat::getName() const
{
    return (_name);
}

int                 Bureaucrat::getGrade() const
{
    return (_grade);
}

void            Bureaucrat::upGrade()
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade -= 1;
}

void            Bureaucrat::downGrade()
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade += 1;
}

void                Bureaucrat::signForm(Form& ref)
{
    try
    {
        ref.beSigned(*this);
        std::cout << _name << " signs " << ref.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " cannot sign " << ref.getName() << "because ";
        std::cerr << e.what() << '\n';
    }
    
}

void                Bureaucrat::executeForm(Form const & form)
{
    try
    {
        form.execute(*this);
        std::cout << getName() << " executes " << form.getName() << "." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << getName() << " cannot execute " << form.getName() << " because ";
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
