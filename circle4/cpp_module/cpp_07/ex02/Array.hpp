#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T>
class Array
{
private:
	T               *_element;
	unsigned int    _n;

public:
	Array() : _element(nullptr), _n(0) {};  // 기본 생성자
	Array(unsigned int n) : _element(new T[n]), _n(n) {};  // 생성자
	Array(const Array& ref)  // 복사 생성자
	{
		*this = ref;
	};
	Array& operator=(const Array& ref)  // 대입 연산자 오버로딩
	{
		if (this == &ref)
			return (*this);
		_n = ref.size();
		_element = new T[_n];  // 메모리할당
		for (int i = 0; i < _n; i++)  // 깊은복사를 위해 하나하나 다복사
			_element[i] = ref._element[i];
		return (*this);
	};
	virtual ~Array()  // 소멸자
	{
		delete []_element;
	};

	T& operator[](unsigned int idx)  // 인덱스 접근을위해 []연산자 오버로딩
	{
		if (idx < 0 || idx >= _n)  // 인덱스 범위가 이상하면
			throw OutofIndex();  // 예외처리
		return (_element[idx]);
	};
	// const 객체에도 인덱스 접근 가능하도록 
	const T& operator[](unsigned int idx) const  // 인덱스 접근을위해 []연산자 오버로딩
	{
		if (idx < 0 || idx >= _n)  // 인덱스 범위가 이상하면
			throw OutofIndex();  // 예외처리
		return (_element[idx]);
	};
	class OutofIndex : public std::exception
	{
		virtual const char* what() const throw()
		{
			return ("Out of Index.");
		};
	};
	unsigned int    size(void) {return(_n);};  // _n을 반환하는 함수
};

#endif