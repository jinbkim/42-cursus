// 참조자에 대해 알아가는 문제

// "HI THIS IS BRAIN" 이 문자열을 포인터변수와 참조자로 가리키기
// 그리고 포인터와 참조자로 문자열 출력하기
// 포인터는 str을 가리키는거고 참조자는 별칭 같은것

#include <iostream>

int     main(void)
{
    std::string	str="HI THIS IS BRAIN";
    std::string	*ptr = 	&str;
    std::string	&ref =	str;

	std::cout<<"str : "<<str<<'\n';
	std::cout<<"ptr : "<<*ptr<<'\n';
	std::cout<<"ref : "<<ref<<'\n';

	// std::cout<<"str address : "<<&str<<'\n';
	// std::cout<<"ptr address : "<<&ptr<<'\n';
	// std::cout<<"ref address : "<<&ref<<'\n';	
}