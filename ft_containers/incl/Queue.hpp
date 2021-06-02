#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> >
	class queue
	{
	public:
		typedef T value_type;
		typedef Container container_type;
		typedef unsigned long size_type;

	protected:
		container_type c;

	public:
		explicit queue(const container_type &ctnr = container_type()) : c(ctnr){};
		queue(const queue &other)
		{
			*this = other;
		};
		~queue(void){};
		queue &operator=(const queue &other)
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
		value_type &front(void)
		{
			return (c.front());
		};
		const value_type &front(void) const
		{
			return (c.front());
		};
		value_type &back(void)
		{
			return (c.back());
		};
		const value_type &back(void) const
		{
			return (c.back());
		};
		void push(const value_type &value)
		{
			return (c.push_back(value));
		};
		void pop(void)
		{
			c.pop_front();
		};
		bool operator==(const queue<T, Container> &q)
		{
			return (this->c == q.c);
		};
		bool operator!=(const queue<T, Container> &q)
		{
			return (this->c != q.c);
		};
		bool operator>(const queue<T, Container> &q)
		{
			return (this->c > q.c);
		};
		bool operator<(const queue<T, Container> &q)
		{
			return (this->c < q.c);
		};
		bool operator>=(const queue<T, Container> &q)
		{
			return (this->c >= q.c);
		};
		bool operator<=(const queue<T, Container> &q)
		{
			return (this->c <= q.c);
		};
	};
};
#endif