// 로봇토미에게 부탁하는 클래스

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	RobotomyRequestForm();

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();

	void    execute(Bureaucrat const & executor) const;
};


#endif