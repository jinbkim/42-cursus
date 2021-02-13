// 전화번호부를 만드는 과제
// 간단한 클래스를 만들어보는과제

// 에러처리
// 1. 중간에 eof(ctrl d) 를 누르면 강제종료
// 2. 이상한 메세지 들어가면 wrong input 출력
// 3. 존재하지 않는 인덱스를 입력하면 wrong index 출력
// 전에 틀린이유는 처음에 명령어를 입력받을때 getline함수로 한줄을 읽는게 아니라 cin 으로 입력받아서 ADD ASDAS 이런식으로 읽으면 ADD를 읽게되고 ASDAS를 다음인자 로 받게되는 이상하게 처리가됬었음

// 보통 클래스의 변수들은 private, 함수들은 public

#include "phoneBook.hpp"

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
		std::getline(std::cin, cmd);  // 명령어 읽기
		if (std::cin.eof())  // eof(ctrl+d)를 만나면
			return (-1);  // 에러표사
		std::cout<<"-------------------------------------------\n\n";
		if (cmd == "ADD")  // 폰북에 데이터 추가
			pb.addContact();
		else if (cmd == "SEARCH")  // 폰북 검색
			pb.searchContact();
		else if (cmd == "EXIT")  // 프로그램 종료
		{
			print("Good Bye! My Awesome PhoneBook");
			return (0);
		}
		else
			print("wrong input!");
	}
	return (-1);
}