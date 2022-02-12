// 템플릿을 이용하여 배열 역할을 하는 클래스 만들기
// const 객체도 인덱스에 접근 가능하도록 오버로딩 하기

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

	// const 객체에도 인덱스 접근은 가능
	// const 객체를 반환하는 []연산자 오버로딩을 하지않으면 에러남 
	Array<double> const arr3(3);
	for(int i=0; i<3 ; i++)
		std::cout<<arr3[i]<<' ';
	std::cout<<'\n';
}