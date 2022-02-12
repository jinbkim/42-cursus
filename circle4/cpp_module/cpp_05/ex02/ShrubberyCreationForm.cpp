// 관목숲을 만드는 클래스

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// 생성자
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation", 145, 137), _target(target)
{
}

// 복사생성자
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& ref) : Form(ref), _target(ref._target)
{
}

// 대입연산자 오버로딩
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& ref)
{
    if (this == &ref)
        return (*this);
    Form::operator=(ref);
    return (*this);
}

// 소멸자
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

// 관목숲을 만드는 함수
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