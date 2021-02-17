/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:21:29 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/23 10:35:19 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : Form("Robotomy Request", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref)
    : Form(ref), _target(ref._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
    if (this == &ref)
        return (*this);
    Form::operator=(ref);
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void    RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    std::cout << "* rizzz...bzzz... *" << std::endl;
    int ret = rand();
    if(ret % 2)
        std::cout << _target << " has been robotomized succesfully." << std::endl;
    else
        std::cout << _target << " robotomization has failed." << std::endl;
}