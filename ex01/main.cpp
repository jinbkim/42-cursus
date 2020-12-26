#include "main.hpp"

int		main(void)
{
	std::string	cmd;

	while (1)
	{
		std::cout<<"--------------------------------------------------\n";
		std::cout<<"-------------- My Awesome PhoneBook --------------\n";
		std::cout<<"--------------------------------------------------\n\n";
		std::cout<<"select (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			
		}
		else if (cmd == "SEARCH")
		{

		}
		else if (cmd == "EXIT")
		{
			std::cout<<"--------------------------------------------------\n";
			std::cout<<"--------- Good Bye! My Awesome PhoneBook ---------\n";
			std::cout<<"--------------------------------------------------\n\n";
			break ;
		}
		else
			std::cout<<"wrong input!\n";
	}
	return (0);
}