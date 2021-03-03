#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Span
{
private:
	unsigned int        _n;
	std::vector<int>    _v; 
	Span();

public:
	Span(unsigned int n);
	Span(const Span& ref);
	Span& operator=(const Span& ref);
	~Span();

	std::vector<int>    getVector();
	void                addNumber(int value);
	template<typename InputIterator>
	void addNumber(InputIterator begin, InputIterator end);
	unsigned int        longestSpan();
	unsigned int        shortestSpan();

	class NoSpaceException : public std::exception
	{
		virtual const char* what() const throw();
	};
	class NoSpanException : public std::exception
	{
		virtual const char* what() const throw();
	};
};

#endif