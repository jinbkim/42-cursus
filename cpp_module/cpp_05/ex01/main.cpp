/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:44:14 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/24 09:23:40 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int     main(void)
{
    std::cout << "\033[1;31mFORM CLASS TEST\033[0m" << std::endl;

    Form formA("formA", 6, 100);
    Form formB("formB", 3, 100);
    Form formC("formC", 5, 40);
    Form *formD;

    std::cout << formA << formB << formC;

    try
    {
        formD = new Form("formD", 0, 140);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    Bureaucrat D("D", 5);
    try
    {
        D.signForm(formA);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        D.signForm(formB);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}