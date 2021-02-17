/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:44:14 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/23 11:32:50 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int     main(void)
{
    std::cout << "\033[1;31mVARIOUS FORM CLASSES TEST\033[0m" << std::endl;

    std::cout << "\033[0;40;34mtry to execute without sign\033[0m" << std::endl;
    ShrubberyCreationForm S("home");
    Bureaucrat A("Yeji", 130);
    A.executeForm(S);

    std::cout << "\033[0;40;34mtry to execute with sign\033[0m" << std::endl;
    A.signForm(S);
    A.executeForm(S);
    
    std::cout << "\033[0;40;34mtry to execute Presidential Pardon Form with low grade\033[0m" << std::endl;
    PresidentialPardonForm P("Trump");
    Bureaucrat B("Zuno", 20); // enough grade to sign but not enough to execute
    B.signForm(P);
    B.executeForm(P);

    std::cout << "\033[0;40;34mtry to execute Robotomy Request Form with sufficient grade\033[0m" << std::endl;
    RobotomyRequestForm R("BMO");
    Bureaucrat C("Jake", 30); // enough grade to sign but not enough to execute
    C.signForm(R);
    C.executeForm(R);    
}