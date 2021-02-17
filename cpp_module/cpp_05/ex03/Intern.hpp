/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:34:34 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/23 14:48:28 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& ref);
        Intern& operator=(const Intern& ref);
        ~Intern();

        Form*   makeForm(std::string formName, std::string target);
    
        class InvalidTypeException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif