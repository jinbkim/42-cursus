#ifndef TESTS_HPP
# define TESTS_HPP

# include <iostream>

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>

# include "Vector.hpp"
# include "List.hpp"
# include "Map.hpp"
# include "Queue.hpp"
# include "Stack.hpp"

# define RESET "\e[0m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"

# define GOOD "⭕"
# define FAIL "❌"

# define WIDTH 38

void test_vector(void);
void test_list(void);
void test_map(void);
void test_stack(void);
void test_queue(void);

inline void print_header(std::string str, bool title = false)
{
	int margin1 = (WIDTH - str.length()) / 2;
	int margin2 = margin1;

	if (str.length() % 2)
		margin2++;
	if (title)
		std::cout << RED << std::endl;
	else
		std::cout << BLUE << std::endl;
	std::cout << std::string(WIDTH + 2, '*') << std::endl;
	std::cout << "*" << std::string(margin1, ' ') << str << std::string(margin2, ' ') << "*" << std::endl;
	std::cout << std::string(WIDTH + 2, '*') << std::endl;
	std::cout << RESET;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(WIDTH - 2 - name.length(), ' ');
	if (a == b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(WIDTH - 2 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << FAIL << std::endl;
};

template <typename T>
bool operator==(ft::Vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
		if (a[i] != b[i])
			return (false);
	return (true);
};

template <typename T>
bool operator==(ft::List<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::List<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::Map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::Map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif