/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 22:36:11 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/21 22:36:11 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;
        Form();

    public:
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form& ref);
        Form& operator=(const Form& ref);
        virtual ~Form();

        std::string getName() const;
        bool        getSigned() const;
        int         getSignGrade() const;
        int         getExecuteGrade() const;

        void        beSigned(Bureaucrat& ref);

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