#ifndef STACK_HPP
# define STACK_HPP

# include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class stack
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef unsigned long size_type;

	protected:
		container_type c;

	public:
		explicit stack(const container_type &ctnr = container_type()) : c(ctnr){};
		stack(const stack &other)
		{
			*this = other;
		};
		~stack(void){};
		stack &operator=(const stack &other)
		{
			this->c = other.c;
			return (*this);
		};
		bool empty(void) const
		{
			return (c.empty());
		};
		size_type size(void) const
		{
			return (c.size());
		};
		value_type &top(void)
		{
			return (c.back());
		};
		const value_type &top(void) const
		{
			return (c.back());
		};
		void push(const value_type &value)
		{
			c.push_back(value);
		};
		void pop(void)
		{
			c.pop_back();
		};
		bool operator==(const stack<T, Container> &s)
		{
			return (this->c == s.c);
		}
		bool operator!=(const stack<T, Container> &s)
		{
			return (this->c != s.c);
		};
		bool operator>(const stack<T, Container> &s)
		{
			return (this->c > s.c);
		};
		bool operator<(const stack<T, Container> &s)
		{
			return (this->c < s.c);
		};
		bool operator>=(const stack<T, Container> &s)
		{
			return (this->c >= s.c);
		};
		bool operator<=(const stack<T, Container> &s)
		{
			return (this->c <= s.c);
		};
	};
};
#endif