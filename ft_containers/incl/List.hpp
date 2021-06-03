#ifndef list_HPP
# define list_HPP

# include "utils.hpp"

namespace ft
{
	template <class T>
	class listIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef Node<T> *pointer;

	protected:
		pointer _ptr;
		
	public:
		listIterator(void){};
		listIterator(const listIterator &other)
		{
			*this = other;
		};
		listIterator(pointer ptr) : _ptr(ptr){};
		~listIterator(void){};
		pointer node(void) const
		{
			return (_ptr);
		};
		listIterator &operator=(const listIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		listIterator &operator++(void)
		{
			_ptr = _ptr->next;
			return (*this);
		};
		listIterator &operator--(void)
		{
			_ptr = _ptr->prev;
			return (*this);
		};
		listIterator operator++(int)
		{
			listIterator tmp(*this);
			operator++();
			return (tmp);
		};
		listIterator operator--(int)
		{
			listIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const listIterator &other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const listIterator &other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const listIterator &other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const listIterator &other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const listIterator &other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const listIterator &other) const
		{
			return (_ptr <= other._ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->data);
		};
		value_type *operator->(void)
		{
			return (_ptr->data);
		};
		listIterator operator+(int n) const
		{
			listIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		listIterator operator-(int n) const
		{
			listIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		listIterator &operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		listIterator &operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};



	template <class T>
	class ConstlistIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef Node<T> *pointer;

	protected:
		pointer _ptr;

	public:
		ConstlistIterator(void){};
		ConstlistIterator(const ConstlistIterator &other)
		{
			*this = other;
		};
		ConstlistIterator(pointer ptr)
			: _ptr(ptr){};
		~ConstlistIterator(void){};
		pointer node(void) const
		{
			return (_ptr);
		};
		ConstlistIterator &operator=(const ConstlistIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		ConstlistIterator &operator++(void)
		{
			_ptr = _ptr->next;
			return (*this);
		};
		ConstlistIterator &operator--(void)
		{
			_ptr = _ptr->prev;
			return (*this);
		};
		ConstlistIterator operator++(int)
		{
			ConstlistIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstlistIterator operator--(int)
		{
			ConstlistIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstlistIterator &other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstlistIterator &other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const ConstlistIterator &other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const ConstlistIterator &other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const ConstlistIterator &other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const ConstlistIterator &other) const
		{
			return (_ptr <= other._ptr);
		};
		const value_type &operator*(void)
		{
			return (_ptr->data);
		};
		const value_type *operator->(void)
		{
			return (_ptr->data);
		};
		ConstlistIterator operator+(int n) const
		{
			ConstlistIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstlistIterator operator-(int n) const
		{
			ConstlistIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstlistIterator &operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ConstlistIterator &operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};



	template <class T>
	class ReverselistIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef Node<T> *pointer;

	protected:
		pointer _ptr;

	public:
		ReverselistIterator(void){};
		ReverselistIterator(const ReverselistIterator &other)
		{
			*this = other;
		};
		ReverselistIterator(pointer ptr)
		{
			this->_ptr = ptr;
		};
		~ReverselistIterator(void){};
		ReverselistIterator &operator++(void)
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ReverselistIterator &operator--(void)
		{
			this->_ptr = this->_ptr->next;
			return (*this);
		};
		ReverselistIterator operator++(int)
		{
			ReverselistIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ReverselistIterator operator--(int)
		{
			ReverselistIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ReverselistIterator &other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ReverselistIterator &other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const ReverselistIterator &other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const ReverselistIterator &other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const ReverselistIterator &other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const ReverselistIterator &other) const
		{
			return (_ptr <= other._ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->data);
		};
		value_type *operator->(void)
		{
			return (_ptr->data);
		};
		ReverselistIterator operator+(int n) const
		{
			ReverselistIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ReverselistIterator operator-(int n) const
		{
			ReverselistIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ReverselistIterator &operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ReverselistIterator &operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};



	template <class T>
	class ConstReverselistIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef Node<T> *pointer;

	protected:
		pointer _ptr;

	public:
		ConstReverselistIterator(void){};
		ConstReverselistIterator(const ConstReverselistIterator &other)
		{
			*this = other;
		};
		ConstReverselistIterator(pointer ptr)
		{
			this->_ptr = ptr;
		};
		~ConstReverselistIterator(void){};
		ConstReverselistIterator &operator++(void)
		{
			this->_ptr = this->_ptr->prev;
			return (*this);
		};
		ConstReverselistIterator &operator--(void)
		{
			this->_ptr = this->_ptr->next;
			return (*this);
		};
		ConstReverselistIterator operator++(int)
		{
			ConstReverselistIterator tmp(*this);
			operator++();
			return (tmp);
		};
		ConstReverselistIterator operator--(int)
		{
			ConstReverselistIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const ConstReverselistIterator &other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ConstReverselistIterator &other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const ConstReverselistIterator &other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const ConstReverselistIterator &other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const ConstReverselistIterator &other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const ConstReverselistIterator &other) const
		{
			return (_ptr <= other._ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->data);
		};
		value_type *operator->(void)
		{
			return (_ptr->data);
		};
		ConstReverselistIterator operator+(int n) const
		{
			ConstReverselistIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ConstReverselistIterator operator-(int n) const
		{
			ConstReverselistIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		ConstReverselistIterator &operator+=(int n)
		{
			while (n < 0)
			{
				(*this)--;
				n++;
			}
			while (n > 0)
			{
				(*this)++;
				n--;
			}
			return (*this);
		};
		ConstReverselistIterator &operator-=(int n)
		{
			while (n > 0)
			{
				operator--();
				n--;
			}
			while (n < 0)
			{
				operator++();
				n++;
			}
			return (*this);
		};
	};



	template <class T, class Alloc = std::allocator<T> >
	class list
	{
	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef unsigned long size_type;
		typedef Node<value_type> *node;
		typedef listIterator<value_type> iterator;
		typedef ConstlistIterator<value_type> const_iterator;
		typedef ReverselistIterator<value_type> reverse_iterator;
		typedef ConstReverselistIterator<value_type> const_reverse_iterator;

	private:
		node _list_begin;
		node _list_end;
		allocator_type _allocator;
		size_t _length;
		Node<value_type> *_new_node(value_type value, Node<value_type> *prev, Node<value_type> *next)
		{
			node node = new Node<value_type>();
			node->data = value;
			node->prev = prev;
			node->next = next;
			return (node);
		};
		void _init_list(void)
		{
			_list_begin = _new_node(value_type(), 0, 0);
			_list_end = _new_node(value_type(), _list_begin, 0);
			_list_begin->next = _list_end;
		};
		template <typename N>
		struct _Smaller
		{
			bool operator()(const N &a, const N &b)
			{
				return a < b;
			};
		};
		template <typename N>
		struct _Equal
		{
			bool operator()(const N &a, const N &b)
			{
				return a == b;
			};
		};

	public:
		explicit list(const allocator_type &alloc = allocator_type()) : _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
		{
			_init_list();
		};
		explicit list(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()) : _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
		{
			_init_list();
			assign(n, value);
		};
		template <class InputIterator>
		list(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0) : _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
		{
			(void)tmp;
			_init_list();
			assign(first, last);
		};
		list(const list &other) : _list_begin(0), _list_end(0), _allocator(other._allocator), _length(0)
		{
			_init_list();
			*this = other;
		};
		~list(void)
		{
			clear();
			delete _list_begin;
			delete _list_end;
		};
		list &operator=(const list &other)
		{
			clear();
			assign(other.begin(), other.end());
			_length = other._length;
			return (*this);
		};
		iterator begin(void)
		{
			return (iterator(_list_begin->next));
		};
		const_iterator begin(void) const
		{
			return (const_iterator(_list_begin->next));
		};
		iterator end(void)
		{
			return (iterator(_list_end));
		};
		const_iterator end(void) const
		{
			return (const_iterator(_list_end));
		};
		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(_list_end->prev));
		};
		const_reverse_iterator rbegin(void) const
		{
			return (const_reverse_iterator(_list_end->prev));
		};
		reverse_iterator rend(void)
		{
			return (reverse_iterator(_list_begin));
		};
		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(_list_begin));
		};
		bool empty(void) const
		{
			return (_length == 0);
		};
		size_type size(void) const
		{
			return (_length);
		};
		// numeric_limits<size_type>::max()
		// size_type 타입이 나타낼수 있는 최대값
		size_type max_size(void) const
		{
			return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
		};
		reference front(void)
		{
			return (_list_begin->next->data);
		};
		const_reference front(void) const
		{
			return (_list_begin->next->data);
		};
		reference back(void)
		{
			return (_list_end->prev->data);
		};
		const_reference back(void) const
		{
			return (_list_end->prev->data);
		};
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0)
		{
			(void)tmp;
			clear();
			while (first != last)
				push_back(*(first++));
		};
		void assign(size_type n, const value_type &value)
		{
			clear();
			while (n--)
				push_back(value);
		};
		void push_front(const value_type &value)
		{
			node el = _new_node(value, _list_begin, _list_begin->next);
			_list_begin->next->prev = el;
			_list_begin->next = el;
			++_length;
		};
		void pop_front(void)
		{
			node next = _list_begin->next->next;
			delete _list_begin->next;
			_list_begin->next = next;
			next->prev = _list_begin;
			_length--;
		};
		void push_back(const value_type &value)
		{
			node el = _new_node(value, _list_end->prev, _list_end);
			_list_end->prev->next = el;
			_list_end->prev = el;
			++_length;
		}
		void pop_back(void)
		{
			node before = _list_end->prev->prev;
			delete _list_end->prev;
			before->next = _list_end;
			_list_end->prev = before;
			_length--;
		};
		iterator insert(iterator position, const value_type &value)
		{
			if (position == begin())
			{
				push_front(value);
				return (begin());
			}
			if (position == end())
			{
				push_back(value);
				return (end());
			}
			node after = position.node();
			node before = after->prev;
			node el = _new_node(value, before, after);
			before->next = el;
			after->prev = el;
			++_length;
			return (iterator(el));
		};
		void insert(iterator position, size_type n, const value_type &value)
		{
			while (n--)
				position = insert(position, value);
		};
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0)
		{
			(void)tmp;
			while (first != last)
			{
				position = insert(position, *(first++));
				if (position != end())
					position++;
			}
		};
		iterator erase(iterator position)
		{
			if (position == begin())
			{
				pop_front();
				return (begin());
			}
			if (position == end())
			{
				pop_back();
				return (end());
			}
			node next = position.node()->next;
			node previous = position.node()->prev;
			delete position.node();
			previous->next = next;
			next->prev = previous;
			_length--;
			return (iterator(next));
		};
		iterator erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
			return (first);
		};
		void swap(list &x)
		{
			ft::swap(x._length, _length);
			ft::swap(x._list_begin, _list_begin);
			ft::swap(x._list_end, _list_end);
		};
		void resize(size_type n, value_type value = value_type())
		{
			while (n < _length)
				pop_back();
			while (n > _length)
				push_back(value);
		};
		void clear(void)
		{
			node cur = _list_begin->next;
			while (cur != _list_end)
			{
				node next = cur->next;
				delete cur;
				cur = next;
			}
			_list_begin->next = _list_end;
			_list_end->prev = _list_begin;
			_length = 0;
		};
		// 인자로 들어온 리스트 x의 원소 -> 해당 리스트
		void splice(iterator position, list &x)
		{
			splice(position, x, x.begin(), x.end());
		};
		void splice(iterator position, list &x, iterator i)
		{
			insert(position, *i);
			x.erase(i);
		};
		void splice(iterator position, list &x, iterator first, iterator last)
		{
			insert(position, first, last);
			x.erase(first, last);
		};
		void remove(const value_type &value)
		{
			iterator c = begin();
			while (c != end())
			{
				if (*c == value)
					c = erase(c);
				else
					c++;
			}
		};
		template <class Predicate>
		void remove_if(Predicate pred)
		{
			iterator c = begin();
			while (c != end())
			{
				if (pred(*c))
					c = erase(c);
				else
					c++;
			}
		};
		void unique(void)
		{
			unique(_Equal<value_type>());
		};
		template <class BinaryPredicate>
		void unique(BinaryPredicate binary_pred)
		{
			iterator prev = begin();
			iterator next = prev;
			while (next + 1 != end())
			{
				++next;
				if (binary_pred(*prev, *next))
				{
					erase(next);
					next = prev;
				}
				else
					prev = next;
			}
		};
		// merge sort
		void merge(list &x)
		{
			merge(x, _Smaller<value_type>());
		};
		template <class Compare>
		void merge(list &x, Compare comp)
		{
			if (&x == this)
				return;
			list tmp;
			iterator it1 = begin();
			iterator it2 = x.begin();
			while (it1 != end() && it2 != x.end())
			{
				if(!comp(*it1, *it2))
					tmp.push_back(*it2++);
				else
					tmp.push_back(*it1++);
			}
			while (it1 != end())
				tmp.push_back(*it1++);
			while (it2 != x.end())
				tmp.push_back(*it2++);
			*this = tmp;
			x.clear();
		};
		void sort(void)
		{
			sort(_Smaller<value_type>());
		};
		template <class Compare>
		void sort(Compare comp)
		{
			iterator a = begin();
			iterator b;
			while (a + 1 != end())
			{
				b = a + 1;
				while (b != end())
				{
					if (!comp(*a, *b))
						ft::swap(*a, *b);
					b++;
				}
				a++;
			}
		};
		void reverse(void)
		{
			list<value_type> tmp;
			iterator it = begin();
			while (it != end())
				tmp.push_front(*(it++));
			*this = tmp;
		};
	};
	template <class T, class Alloc>
	void swap(list<T, Alloc> &x, list<T, Alloc> &y)
	{
		x.swap(y);
	};
	template <typename T>
	bool operator==(list<T> const &lhs, list<T> const &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename list<T>::const_iterator cur1 = lhs.begin();
		typename list<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*(cur1++) != *(cur2++))
				return (false);
		}
		return (true);
	};
	template <typename T>
	bool operator!=(list<T> const &lhs, list<T> const &rhs)
	{
		return (!(lhs == rhs));
	};
	template <typename T>
	bool operator<(list<T> const &lhs, list<T> const &rhs)
	{
		if (lhs.size() < rhs.size())
			return (true);
		if (lhs.size() > rhs.size())
			return (false);
		typename list<T>::const_iterator cur1 = lhs.begin();
		typename list<T>::const_iterator cur2 = rhs.begin();
		while (cur1 != lhs.end())
		{
			if (*cur1 != *cur2)
				return (*cur1 < *cur2);
			cur1++;
			cur2++;
		}
		return (false);
	};
	template <typename T>
	bool operator<=(list<T> const &lhs, list<T> const &rhs)
	{
		return (!(rhs < lhs));
	};
	template <typename T>
	bool operator>(list<T> const &lhs, list<T> const &rhs)
	{
		return (rhs < lhs);
	};
	template <typename T>
	bool operator>=(list<T> const &lhs, list<T> const &rhs)
	{
		return (!(lhs < rhs));
	};
};

#endif