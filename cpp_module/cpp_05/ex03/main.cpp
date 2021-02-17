/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:44:14 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/23 15:13:37 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int     main(void)
{
    std::cout << "\033[1;31mINTERN CLASS TEST\033[0m" << std::endl;

    Intern A;
    Intern B;
    Intern C;

    std::cout << "\033[0;40;34mmake Shrubbery Creation Form\033[0m" << std::endl;
    Form* S = A.makeForm("shrubbery creation", "tree");

    std::cout << "\033[0;40;34mbureaucrat with sufficient grade signs\033[0m" << std::endl;
    Bureaucrat Yeji = Bureaucrat("Yeji", 130);
    Yeji.signForm(*S);
    std::cout << "\033[0;40;34mbureaucrat with sufficient grade executes\033[0m" << std::endl;
    Yeji.executeForm(*S);

    std::cout << std::endl;
    std::cout << "\033[0;40;34mmake Presidential Pardon Form\033[0m" << std::endl;
    B.makeForm("presidential pardon", "trump");

    std::cout << std::endl;
    std::cout << "\033[0;40;34mmake Robotomy Request Form\033[0m" << std::endl;
    C.makeForm("robotomy request", "BMO");

    std::cout << std::endl;
    std::cout << "\033[0;40;34mmake Invalid Form\033[0m" << std::endl;
    try
    {
        C.makeForm("invalid", "hoho");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);    
}