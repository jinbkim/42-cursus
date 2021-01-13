#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Bureaucrat
{
private:
	Bureaucrat();
	std::string	const	name;
	int					grade;

public:
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);
	~Bureaucrat();
	Bureaucrat	&operator=(Bureaucrat const &other);

	class	GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	class	GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	std::string const	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const &b);

#endif