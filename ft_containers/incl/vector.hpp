
#ifndef VECTOR_HPP
# define VECTOR_HPP

# include "utils.hpp"

namespace ft
{
	template <class T>
	class vectorIterator
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;

	protected:
		pointer _ptr;

	public:
		vectorIterator(void){};
		vectorIterator(const vectorIterator &other)
		{
			*this = other;
		};
		vectorIterator(pointer ptr) : _ptr(ptr){};
		~vectorIterator(void){};
		vectorIterator &operator=(const vectorIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		vectorIterator &operator++(void)
		{
			_ptr++;
			return (*this);
		};
		vectorIterator &operator--(void)
		{
			_ptr--;
			return (*this);
		};
		vectorIterator operator++(int)
		{
			vectorIterator tmp(*this);
			operator++();
			return (tmp);
		};
		vectorIterator operator--(int)
		{
			vectorIterator tmp(*this);
			operator--();
			return (tmp);
		};
		bool operator==(const vectorIterator &other) const
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const vectorIterator &other) const
		{
			return (_ptr != other._ptr);
		};
		bool operator>(const vectorIterator &other) const
		{
			return (_ptr > other._ptr);
		};
		bool operator>=(const vectorIterator &other) const
		{
			return (_ptr >= other._ptr);
		};
		bool operator<(const vectorIterator &other) const
		{
			return (_ptr < other._ptr);
		};
		bool operator<=(const vectorIterator &other) const
		{
			return (_ptr <= other._ptr);
		};
		value_type &operator*(void)
		{
			return (*_ptr);
		};
		value_type *operator->(void)
		{
			return (_ptr);
		};
		vectorIterator operator+(int n) const
		{
			vectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		vectorIterator operator-(int n) const
		{
			vectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		vectorIterator &operator+=(int n)
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
		vectorIterator &operator-=(int n)
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
		value_type &operator[](int n) const
		{
			return (*(*this + n));
		}
	};



	template <class T>
	class ReversevectorIterator : public vectorIterator<T>
	{
	public:
		typedef T value_type;
		typedef T &reference;
		typedef T *pointer;
		ReversevectorIterator(void){};
		ReversevectorIterator(const ReversevectorIterator &other)
		{
			*this = other;
		};
		ReversevectorIterator(pointer ptr)
		{
			this->_ptr = ptr;
		}
		~ReversevectorIterator(void){};
		ReversevectorIterator &operator=(const ReversevectorIterator &other)
		{
			this->_ptr = other.ptr;
			return (*this);
		}
		ReversevectorIterator &operator++(void)
		{
			this->_ptr--;
			return (*this);
		};
		ReversevectorIterator operator++(int)
		{
			ReversevectorIterator tmp(*this);
			this->_ptr--;
			return (tmp);
		};
		ReversevectorIterator &operator--(void)
		{
			this->_ptr++;
			return (*this);
		};
		ReversevectorIterator operator--(int)
		{
			ReversevectorIterator tmp(*this);
			tmp._ptr++;
			rteurn(tmp);
		};
		ReversevectorIterator operator+=(int n)
		{
			while (n > 0)
			{
				operator++();
				n--;
			}
			while (n < 0)
			{
				operator--();
				n++;
			}
			return (*this);
		};
		ReversevectorIterator operator-=(int n)
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
		bool operator==(const ReversevectorIterator &other) const
		{
			return (this->_ptr == other._ptr);
		};
		bool operator!=(const ReversevectorIterator &other) const
		{
			return (this->_ptr != other._ptr);
		};
		bool operator>(const ReversevectorIterator &other) const
		{
			return (this->_ptr > other._ptr);
		};
		bool operator>=(const ReversevectorIterator &other) const
		{
			return (this->_ptr >= other._ptr);
		};
		bool operator<(const ReversevectorIterator &other) const
		{
			return (this->_ptr < other._ptr);
		};
		bool operator<=(const ReversevectorIterator &other) const
		{
			return (this->_ptr <= other._ptr);
		};
		value_type &operator*(void)
		{
			return (*this->_ptr);
		};
		value_type *operator->(void)
		{
			return (this->_ptr);
		};
		ReversevectorIterator operator+(int n) const
		{
			ReversevectorIterator tmp(*this);
			tmp += n;
			return (tmp);
		};
		ReversevectorIterator operator-(int n) const
		{
			ReversevectorIterator tmp(*this);
			tmp -= n;
			return (tmp);
		};
		value_type &operator[](int n) const
		{
			return (*(*this - n));
		};
	};



	template <typename T, typename A = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef A allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef ft::vectorIterator<T> iterator;
		typedef ft::vectorIterator<const T> const_iterator;
		typedef ft::ReversevectorIterator<T> reverse_iterator;
		typedef ft::ReversevectorIterator<const T> const_reverse_iterator;
		typedef unsigned long size_type;

	private:
		size_type _container_size;  // 실제로 사용중인 메모리 크기 (_container_size <= _container_capacity)
		size_type _container_capacity;  // 할당한 메모리 크기
		pointer _container;
		allocator_type _allocator;

	public:
		explicit vector(const allocator_type &allocator = allocator_type()) : _container_size(0), _container_capacity(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
		};
		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0) : _container_size(0), _container_capacity(0), _container(0), _allocator(allocator)
		{
			(void)tmp;
			_container = _allocator.allocate(0);
			assign(begin, end);
		};
		vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type()) : _container_size(0), _container_capacity(0), _container(0), _allocator(allocator)
		{
			_container = _allocator.allocate(0);
			assign(n, value);
		};
		vector(const vector &other) : _container_size(0), _container_capacity(0), _container(0), _allocator(other._allocator)
		{
			_container = _allocator.allocate(0);
			*this = other;
		};
		~vector(void)
		{
			_allocator.deallocate(_container, _container_capacity);
		};
		vector &operator=(const vector &other)
		{
			if (_container != 0)
				_allocator.deallocate(_container, _container_capacity);
			_allocator = other._allocator;
			_container_capacity = 0;
			_container_size = 0;
			_container = _allocator.allocate(0);
			assign(other.begin(), other.end());
			return (*this);
		};
		iterator begin(void)
		{
			return (iterator(_container));
		};
		const_iterator begin(void) const
		{
			return (const_iterator(_container));
		};
		iterator end(void)
		{
			return (iterator(_container + _container_size));
		};
		const_iterator end(void) const
		{
			return (const_iterator(_container + _container_size));
		};
		reverse_iterator rbegin(void)
		{
			return (reverse_iterator(_container + _container_size - 1));
		};
		const_reverse_iterator rbegin(void) const
		{
			return (const_reverse_iterator(_container + _container_size - 1));
		};
		reverse_iterator rend(void)
		{
			return (reverse_iterator(_container - 1));
		};
		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(_container - 1));
		};
		size_type size(void) const
		{
			return (_container_size);
		};
		// 한 vector에 할당할수 있는 메모리는 64bit-1 = 8byte-1 
		// max() : 자료형이 size_type인 변수가 가질수 있는 최대값
		size_type max_size(void) const
		{
			return (std::numeric_limits<size_type>::max() / sizeof(value_type));
		};
		void resize(size_type n, value_type value = value_type())
		{
			while (n < _container_size)
				pop_back();
			while (n > _container_size)
				push_back(value);
		};
		size_type capacity(void) const
		{
			return (_container_capacity);
		};
		bool empty(void) const
		{
			return (_container_size == 0);
		};
		// 할당된 메모리 크기를 n으로 변경
		// 담겨져 있던 원소들은 그대로
		void reserve(size_type n)
		{
			if (n > _container_capacity)
			{
				pointer tmp;
				tmp = _allocator.allocate(n);
				_container_capacity = n;

				size_type i = -1;
				while (++i < _container_size)
					tmp[i] = _container[i];
				_allocator.deallocate(_container, _container_capacity);
				_container = tmp;
			}
		};
		reference operator[](size_type n)
		{
			return (_container[n]);
		};
		const_reference operator[](size_type n) const
		{
			return (_container[n]);
		};
		// at : 범위 검사 O
		// [] : 범위 검사 X
		reference at(size_type n)
		{
			if (n >= _container_size || n < 0)
				throw std::length_error("vector");
			return _container[n];
		};
		const_reference at(size_type n) const
		{
			if (n >= _container_size || n < 0)
				throw std::length_error("vector");
			return _container[n];
		};
		reference front(void)
		{
			return _container[0];
		};
		const_reference front(void) const
		{
			return _container[0];
		};
		reference back(void)
		{
			return _container[_container_size - 1];
		};
		const_reference back(void) const
		{
			return _container[_container_size - 1];
		};
		void push_back(const value_type &value)
		{
			if (_container_size + 1 > _container_capacity)
				reserve(_container_size + 1);
			_container[_container_size++] = value;
		};
		void pop_back(void)
		{
			if (_container_size)
				_container_size--;
		};
		iterator insert(iterator position, const value_type &value)
		{
			size_type i = 0;
			iterator it = begin();
			while (it + i != position && i < _container_size)
				i++;
			if (_container_capacity == _container_size)
				reserve(_container_size + 1);
			size_type j = _container_capacity;
			while (i < --j)
				_container[j] = _container[j - 1];

			_container[i] = value;
			_container_size++;
			return (iterator(&_container[i]));
		};
		void insert(iterator position, size_type n, const value_type &value)
		{
			while (n--)
				position = insert(position, value);
		};
		template <class InputIterator>
		void insert(iterator position, InputIterator begin, InputIterator end, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0)
		{
			(void)tmp;
			while (begin != end)
			{
				position = insert(position, *begin) + 1;
				++begin;
			}
		};
		// 원소 한개 지우기
		// 지운 원소 뒤에 원소들 한칸씩 앞으로
		iterator erase(iterator position)
		{
			iterator cursor = position - 1;
			while (++cursor + 1 != end())
				*cursor = *(cursor + 1);
			_container_size--;
			return (iterator(position));
		};
		iterator erase(iterator begin, iterator end)
		{
			while (begin != end--)
				erase(begin);
			return (iterator(begin));
		};
		void clear(void)
		{
			erase(begin(), end());
		};
		template <class InputIterator>
		// void assign(InputIterator first, InputIterator last)
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type tmp = 0)
		{
			(void)tmp;
			clear();
			insert(begin(), first, last);
		};
		void assign(size_type n, const value_type &value)
		{
			clear();
			insert(begin(), n, value);
		};
		void swap(vector &other)
		{
			ft::swap(_container, other._container);
			ft::swap(_container_capacity, other._container_capacity);
			ft::swap(_container_size, other._container_size);
		};
	};
	template <class T, class Alloc>
	void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	};
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
			if (a[i] != b[i])
				return (false);
		return (true);
	};
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		return (!(a == b));
	};
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		size_t i;
		size_t n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = -1;
		while (++i < n)
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
		return (a.size() < b.size());
	}
	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		return (a < b || a == b);
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &a, const vector<T, Alloc> &b)
	{
		return (!(a < b));
	}
};

#endif