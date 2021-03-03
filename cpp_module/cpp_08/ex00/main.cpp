// void     easyfind(T t, int value)
// easyfind 만들기
// t안에 value가 있는지 없는지 알려주는 함수
// stl algorithm 사용하라함 : iterator, vector

#include "easyfind.hpp"
#include <vector>

int     main(void)
{
	std::vector<int>	vec1(5);  // 크키가 5인 int형 벡터 생성
	std::vector<char>	vec2(5);  // 크키가 5인 char형 벡터 생성

	// vec1에 1, 2, 3, 4, 5 저장
	for(int i=0; i<vec1.size(); i++)
		vec1[i] = i+1;

	// vec2에 a, b, c, d, e 저장
	for(int i=0; i<vec2.size(); i++)
		vec2[i] = 'a'+i;
	
	// 5있음
	try
	{
		easyfind(vec1, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// 6 없음
	try
	{
		easyfind(vec1, 6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	// a 있음
	try
	{
		easyfind(vec2, 'a');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// z 없음
	try
	{
		easyfind(vec2, 'z');
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}