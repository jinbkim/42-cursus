#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <string>

class NotFoundError: public std::exception
{
public:
	const char* what() const throw()
	{
		return ("Not Found.");
	}
};

// t안에서 value가 있으면 Found, 아니면 Not Found를 출력하는 함수
template <typename T>
void     easyfind(T t, int value)
{
	// find함수가 t안에 value값을 찾은 위치를 반환하여 iterator it에 저장
    typename T::iterator it = std::find(t.begin(), t.end(), value);
    if (it == t.end())  // t안에 value값이 없으면
        throw NotFoundError();
    std::cout << "Found." << std::endl;
}

#endif