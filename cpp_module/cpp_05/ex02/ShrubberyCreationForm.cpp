/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 10:13:55 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/23 10:48:35 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : Form("Shrubbery Creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref)
    : Form(ref), _target(ref._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
    if (this == &ref)
        return (*this);
    Form::operator=(ref);
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    Form::execute(executor);
    
    std::ofstream out(_target + "_shrubbery");

    out <<"                                              .       "<< std::endl;
    out <<"                                   .         ;        "<< std::endl;  
    out <<"      .              .              ;%     ;;         "<< std::endl;
    out <<"        ,           ,                :;%  %;          "<< std::endl;
    out <<"         :         ;                   :;%;'     .,   "<< std::endl;
    out <<",.        %;     %;            ;        %;'    ,;     "<< std::endl;
    out <<"  ;       ;%;  %%;        ,     %;    ;%;    ,%'      "<< std::endl;     
    out <<"   %;       %;%;      ,  ;       %;  ;%;   ,%;'       "<< std::endl;
    out <<"    ;%;      %;        ;%;        % ;%;  ,%;'         "<< std::endl;
    out <<"     `%;.     ;%;     %;'         `;%%;.%;'           "<< std::endl;
    out <<"      `:;%.    ;%%. %@;        %; ;@%;%'              "<< std::endl;    
    out <<"         `:%;.  :;bd%;          %;@%;'                "<< std::endl;            
    out <<"           `@%:.  :;%.         ;@@%;'                 "<< std::endl;    
    out <<"             `@%.  `;@%.      ;@@%;                   "<< std::endl;
    out <<"               `@%%. `@%%    ;@@%;                    "<< std::endl;
    out <<"                 ;@%. :@%%  %@@%;                     "<< std::endl;
    out <<"                   %@bd%%%bd%%:;                      "<< std::endl;    
    out <<"                     #@%%%%%:;;                       "<< std::endl;
    out <<"                     %@@%%%::;                        "<< std::endl;
    out <<"                     %@@@%(o);  . '                   "<< std::endl;    
    out <<"                     %@@@o%;:(.,'                     "<< std::endl;    
    out <<"                 `.. %@@@o%::;                        "<< std::endl;
    out <<"                    `)@@@o%::;                        "<< std::endl;
    out <<"                     %@@(o)::;                        "<< std::endl;
    out <<"                    .%@@@@%::;                        "<< std::endl;
    out <<"                    ;%@@@@%::;.                       "<< std::endl;
    out <<"                   ;%@@@@%%:;;;.                      "<< std::endl;
    out <<"               ...;%@@@@@%%:;;;;,..                   "<< std::endl;
}