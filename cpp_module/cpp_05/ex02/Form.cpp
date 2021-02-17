/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:36:06 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/21 22:36:06 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int executeGrade)
    :_name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& ref)
    : _name(ref.getName()), _signed(getSigned()),
        _signGrade(ref.getSignGrade()), _executeGrade(ref.getExecuteGrade())
{
    if (_signGrade < 1 || _executeGrade < 1)
        throw Form::GradeTooHighException();
    else if (_signGrade > 150 || _executeGrade > 150)
        throw Form::GradeTooLowException();
}

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

void                Form::execute(Bureaucrat const & executor) const
{
    if (_signed == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > _executeGrade)
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

const char* Form::NotSignedException::what() const throw()
{
	return ("FormException: Not Signed");
}

std::ostream&   operator<<(std::ostream &os, const Form &ref)
{
    return (os << ref.getName() <<
        ", sign status " << ref.getSigned() <<
        ", sign grade " << ref.getSignGrade() <<
        ", execute grade " << ref.getExecuteGrade() << std::endl);
}
