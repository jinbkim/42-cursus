/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:34:41 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/24 09:26:00 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& ref)
{
    *this = ref;
}

Intern& Intern::operator=(const Intern& ref)
{
    if (this == &ref)
        return (*this);
    return (*this);
}

Intern::~Intern()
{
}

Form*   Intern::makeForm(std::string formName, std::string target)
{
    std::string targets[3] = 
    {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    Form       *forms[3];
    Form       *result = 0;

    forms[0] = new ShrubberyCreationForm(target);
    forms[1] = new RobotomyRequestForm(target);
    forms[2] = new PresidentialPardonForm(target);

    int i;
    for (i = 0; i < 3; i++)
    {
        if (formName == targets[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            result = forms[i];
            continue;
        }
        delete forms[i];
    }
    if (result != 0)
        return (result);
    throw Intern::InvalidTypeException();
    return nullptr;
}
    
const char* Intern::InvalidTypeException::what() const throw()
{
    return "InternExeption: Invalid Type";
}