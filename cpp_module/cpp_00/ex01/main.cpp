#include "main.hpp"

void	print(const char *s)
{
	std::cout<<"\n>>>>>>>>>> "<<s<<" <<<<<<<<<<\n\n";
}

int		main(void)
{
	std::string	cmd;
	phoneBook	pb;

	while (1)
	{
		print("My Awesome PhoneBook");
		std::cout<<"select (ADD, SEARCH, EXIT) : ";
		std::cin>>cmd;  // 명령어 읽기
		std::cin.ignore();  // 버퍼에 남은 개행 제거
		std::cout<<"-------------------------------------------\n\n";
		if (cmd == "ADD")  // 폰북에 데이터 추가
			pb.addContact();
		else if (cmd == "SEARCH")  // 폰북 검색
			pb.searchContact();
		else if (cmd == "EXIT")  // 프로그램 종료
		{
			print("Good Bye! My Awesome PhoneBook");
			break ;
		}
		else
			print("wrong input!");
	}
	return (0);
}