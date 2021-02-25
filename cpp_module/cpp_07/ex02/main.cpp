// 템플릿을 이용하여 배열 역할을 하는 클래스 만들기
// const 객체도 인덱스에 접근 가능함

#include "Array.hpp"
#include <string>

int main(void)
{
	Array<int>	arr1(10);
	for(int i=0; i<10 ; i++)
		arr1[i] = i;
	for(int i=0; i<10 ; i++)
		std::cout<<arr1[i]<<' ';
	std::cout<<'\n';
	try
	{
		arr1[10] = 10;
	}
	catch(const std::exception& e)
	{
		std::cout<<e.what()<<'\n';
	}

	Array<char>	arr2(0);
	try
	{
		std::cout<<arr2[0];
	}
	catch(const std::exception& e)
	{
		std::cout<<e.what()<<'\n';
	}

	Array<double> const arr3(3);  // const 객체에도 인덱스 접근 가능
	for(int i=0; i<3 ; i++)
		std::cout<<arr3[i]<<' ';
	std::cout<<'\n';
}