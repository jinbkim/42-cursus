#ifndef MAP_HPP
# define MAP_HPP

namespace ft
{
	template <class K, class T>
	class MapIterator
	{
	public:
		typedef std::pair<K, T> value_type;
		typedef std::pair<K, T> &reference;
		typedef BNode<K, T> *pointer;

	protected:
		pointer _ptr;

	private:
		pointer _successor(pointer ptr)
		{
			pointer next;
			if (!ptr->right)
			{
				next = ptr;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->right;
				while (next->left)
					next = next->left;
			}
			return (next);
		};
		pointer _predecessor(pointer ptr)
		{
			pointer next;

			if (!ptr->left)
			{
				next = ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};

	public:
		MapIterator(void) : _ptr(0){};
		MapIterator(const pointer ptr) : _ptr(ptr){};
		MapIterator(const MapIterator &other)
		{
			*this = other;
		};
		MapIterator &operator=(const MapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		pointer node(void)
		{
			return (_ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->pair);
		};
		value_type *operator->(void)
		{
			return (&_ptr->pair);
		};
		bool operator==(const MapIterator<K, T> &other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const MapIterator<K, T> &other)
		{
			return (!(*this == other));
		};
		bool operator>(const MapIterator<K, T> &other)
		{
			return (_ptr > other._ptr);
		};
		bool operator<(const MapIterator<K, T> &other)
		{
			return (_ptr < other._ptr);
		};
		bool operator>=(const MapIterator<K, T> &other)
		{
			return (_ptr >= other._ptr);
		};
		bool operator<=(const MapIterator<K, T> &other)
		{
			return (_ptr <= other._ptr);
		};
		MapIterator &operator++(void)
		{
			_ptr = _successor(_ptr);
			return (*this);
		};
		MapIterator &operator--(void)
		{
			_ptr = _predecessor(_ptr);
			return (*this);
		};
		MapIterator operator++(int)
		{
			MapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		MapIterator operator--(int)
		{
			MapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};



	template <class K, class T>
	class ReverseMapIterator
	{
	public:
		typedef std::pair<K, T> value_type;
		typedef std::pair<K, T> &reference;
		typedef BNode<K, T> *pointer;

	protected:
		pointer _ptr;

	private:
		pointer _successor(pointer ptr)
		{
			pointer next;
			if (!ptr->right)
			{
				next = ptr;
				while (next->parent && next == next->parent->right)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->right;
				while (next->left)
					next = next->left;
			}
			return (next);
		};
		pointer _predecessor(pointer ptr)
		{
			pointer next;

			if (!ptr->left)
			{
				next = ptr;
				while (next->parent && next == next->parent->left)
					next = next->parent;
				next = next->parent;
			}
			else
			{
				next = ptr->left;
				while (next->right)
					next = next->right;
			}
			return (next);
		};

	public:
		ReverseMapIterator(void) : _ptr(0){};
		ReverseMapIterator(const pointer ptr) : _ptr(ptr){};
		ReverseMapIterator(const ReverseMapIterator &other)
		{
			*this = other;
		};
		ReverseMapIterator &operator=(const ReverseMapIterator &other)
		{
			_ptr = other._ptr;
			return (*this);
		};
		pointer node(void)
		{
			return (_ptr);
		};
		value_type &operator*(void)
		{
			return (_ptr->pair);
		};
		value_type *operator->(void)
		{
			return (&_ptr->pair);
		};
		bool operator==(const ReverseMapIterator<K, T> &other)
		{
			return (_ptr == other._ptr);
		};
		bool operator!=(const ReverseMapIterator<K, T> &other)
		{
			return (!(*this == other));
		};
		bool operator>(const ReverseMapIterator<K, T> &other)
		{
			return (_ptr > other._ptr);
		};
		bool operator<(const ReverseMapIterator<K, T> &other)
		{
			return (_ptr < other._ptr);
		};
		bool operator>=(const ReverseMapIterator<K, T> &other)
		{
			return (_ptr >= other._ptr);
		};
		bool operator<=(const ReverseMapIterator<K, T> &other)
		{
			return (_ptr <= other._ptr);
		};
		ReverseMapIterator &operator++(void)
		{
			_ptr = _predecessor(_ptr);
			return (*this);
		};
		ReverseMapIterator &operator--(void)
		{
			_ptr = _successor(_ptr);
			return (*this);
		};
		ReverseMapIterator operator++(int)
		{
			ReverseMapIterator tmp(*this);
			this->operator++();
			return (tmp);
		};
		ReverseMapIterator operator--(int)
		{
			ReverseMapIterator tmp(*this);
			this->operator--();
			return (tmp);
		};
	};



	template <class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef std::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef T &reference;
		typedef const T &const_reference;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef unsigned long size_type;
		typedef BNode<key_type, mapped_type> *node;
		typedef MapIterator<key_type, mapped_type> iterator;
		typedef ReverseMapIterator<key_type, mapped_type> reverse_iterator;
		typedef iterator const_iterator;
		typedef reverse_iterator const_reverse_iterator;
		class value_compare
		{
			friend class map;  // non-member

		protected:
			Compare comp;
			value_compare(Compare c) : comp(c){};

		public:
			typedef bool result_type;
			// typedef value_type first_argument_type;
			// typedef value_type second_argument_type;
			bool operator()(const value_type &x, const value_type &y) const
			{
				return comp(x.first, y.first);
			};
		};

	private:
		allocator_type _allocator;
		key_compare _comp;
		node _root;
		size_type _length;
		// void _debug_tree(node n)
		// {
		// 	if (!n)
		// 		return;
		// 	_debug_tree(n->left);
		// 	if (n->parent && !n->end)
		// 		std::cout << n->pair.first << "=" << n->pair.second << std::endl;
		// 	_debug_tree(n->right);
		// };
		node _new_node(key_type key, mapped_type value, node parent, bool end = false)
		{
			node el = new BNode<key_type, mapped_type>();
			el->pair = std::make_pair(key, value);
			el->right = 0;
			el->left = 0;
			el->parent = parent;
			el->end = end;
			return (el);
		};
		void _free_tree(node n)
		{
			if (n->right)
				_free_tree(n->right);
			if (n->left)
				_free_tree(n->left);
			delete n;
		};
		node _insert_node(node n, key_type key, mapped_type value, bool end = false)
		{
			// std::cout<<"n->pair.first : "<<n->pair.first <<", n->end : "<<n->end<<'\n';
			// std::cout<<"key : "<<key<<", value : "<<value<<", end : "<<end<<'\n';
			if (n->end)
			{
				if (!n->left)
				{
					n->left = _new_node(key, value, n, end);
					return (n->left);
				}
				return (_insert_node(n->left, key, value));
			}
			if (key < n->pair.first && !end)
			{
				if (!n->left)
				{
					n->left = _new_node(key, value, n, end);
					return (n->left);
				}
				else
					return (_insert_node(n->left, key, value));
			}
			else
			{
				if (!n->right)
				{
					n->right = _new_node(key, value, n, end);
					return (n->right);
				}
				else
					return (_insert_node(n->right, key, value));
			}
		};
		node _find(node n, key_type key) const
		{
			node tmp;
			if (!n->end && n->pair.first == key && n->parent)
				return (n);
			if (n->right)
			{
				if ((tmp = _find(n->right, key)))
					return (tmp);
			}
			if (n->left)
			{
				if ((tmp = _find(n->left, key)))
					return (tmp);
			}
			return (0);
		};
		void _delete_node(node n)
		{
			node parent = n->parent;
			if (!n->left && !n->right)
			{
				if (parent->right == n)
					parent->right = 0;
				else
					parent->left = 0;
				delete n;
				return;
			}
			if (n->right && !n->left)
			{
				if (parent->right == n)
					parent->right = n->right;
				else
					parent->left = n->right;
				n->right->parent = parent;
				delete n;
				return;
			}
			if (n->left && !n->right)
			{
				if (parent->right == n)
					parent->right = n->left;
				else
					parent->left = n->left;
				n->left->parent = parent;
				delete n;
				return;
			}
			node next = (++iterator(n)).node();
			// if (!next)
			// 	next = (--iterator(n)).node();
			ft::swap(next->pair, n->pair);
			_delete_node(next);
		};
		void _init_tree(void)
		{
			_root = _new_node(key_type(), mapped_type(), 0);
			_root->right = _new_node(key_type(), mapped_type(), _root, true);
			_length = 0;
		};
		node _end(void) const
		{
			return (_root->right);
		};

	public:
		explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) : _allocator(alloc), _comp(comp)
		{
			_init_tree();
		};
		template <class InputIterator>
		Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type()) : _allocator(alloc), _comp(comp)
		{
			_init_tree();
			insert(first, last);
		};
		Map(const Map<Key, T> &other)
		{
			_init_tree();
			*this = other;
		};
		~Map(void)
		{
			_free_tree(_root);
		};
		Map &operator=(const Map<Key, T> &other)
		{
			clear();
			insert(other.begin(), other.end());
			return (*this);
		};
		iterator begin(void)
		{
			// node n = _root;
			node n = _root->right;
			// if (!n->left && !n->right)
			// 	return (end());
			// if (!n->left && n->right)
			// 	n = n->right;

			while (n->left)
				n = n->left;
			return (iterator(n));
		};
		const_iterator begin(void) const
		{
			// node n = _root;
			node n = _root->right;
			// if (!n->left && !n->right)
			// 	return (end());
			// if (!n->left && n->right)
			// 	n = n->right;

			while (n->left)
				n = n->left;
			return (const_iterator(n));
		};
		iterator end(void)
		{
			return (iterator(_end()));
		};
		const_iterator end(void) const
		{
			return (const_iterator(_end()));
		};
		reverse_iterator rbegin(void)
		{
			iterator i = end();
			i--;
			return (reverse_iterator(i.node()));
		};
		const_reverse_iterator rbegin(void) const
		{
			iterator i = end();
			i--;
			return (const_reverse_iterator(i.node()));
		};
		reverse_iterator rend(void)
		{
			return (reverse_iterator(_root));
		};
		const_reverse_iterator rend(void) const
		{
			return (const_reverse_iterator(_root));
		};
		bool empty(void) const
		{
			return (_length == 0);
		};
		size_type size(void) const
		{
			return (_length);
		};
		size_type max_size(void) const
		{
			return (std::numeric_limits<size_type>::max() / (sizeof(ft::BNode<key_type, mapped_type>)));
		};
		mapped_type &operator[](const key_type &k)
		{
			iterator tmp = find(k);
			if (tmp != end())
				return tmp->second;
			return (insert(std::make_pair(k, mapped_type())).first->second);
		};
		std::pair<iterator, bool> insert(const value_type &value)
		{
			iterator tmp;
			if ((tmp = find(value.first)) != end())
				return (std::make_pair(tmp, false));
			++_length;
			return (std::make_pair(iterator(_insert_node(_root, value.first, value.second)), true));
		};
		iterator insert(iterator position, const value_type &value)
		{
			iterator tmp;
			if ((tmp = find(value.first)) != end())
				return (tmp);
			++_length;
			return (iterator(_insert_node(position.node(), value.first, value.second)));
		};
		template <class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(*first);
				++first;
			}
		};
		void erase(iterator position)
		{
			_delete_node(position.node());
			--_length;
		};
		size_type erase(const key_type &value)
		{
			int i = 0;
			iterator item;
			while ((item = find(value)) != end())
			{
				erase(item);
				++i;
			};
			return (i);
		};
		void erase(iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		};
		void swap(Map &x)
		{
			ft::swap(_length, x._length);
			ft::swap(_root, x._root);
		};
		void clear(void)
		{
			erase(begin(), end());
		};
		key_compare key_comp(void) const
		{
			return (_comp);
		};
		value_compare value_comp(void) const
		{
			return (this->value_compare);
		};
		iterator find(const key_type &value)
		{
			if (empty())
				return (end());
			node tmp = _find(_root, value);
			if (tmp)
				return (iterator(tmp));
			return (end());
		};
		const_iterator find(const key_type &value) const
		{
			if (empty())
				return (end());
			node tmp = _find(_root, value);
			if (tmp)
				return (const_iterator(tmp));
			return (end());
		};
		size_type count(const key_type &value) const
		{
			size_t c = 0;
			const_iterator it = begin();

			while (it != end())
			{
				if (it->first == value)
					++c;
				++it;
			}
			return (c);
		};
		iterator lower_bound(const key_type &key)
		{
			iterator it = begin();
			while (it != end())
			{
				if (this->_comp(it->first, key) <= 0)
					return (it);
				++it;
			}
			return (end());
		};
		const_iterator lower_bound(const key_type &key) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (this->_comp(it->first, key) <= 0)
					return (it);
				++it;
			}
			return (end());
		};
		iterator upper_bound(const key_type &key)
		{
			iterator it = begin();
			while (it != end())
			{
				if (it->first != key && this->_comp(it->first, key) <= 0)
					return (it);
				++it;
			};
			return (end());
		};
		const_iterator upper_bound(const key_type &key) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (it->first != key && this->_comp(it->first, key) <= 0)
					return (it);
				++it;
			};
			return (end());
		};
		std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
		{
			return (std::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
		};
		std::pair<iterator, iterator> equal_range(const key_type &k)
		{
			return (std::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
		};
		// void debug(void)
		// {
		// 	_debug_tree(_root);
		// };
	};
	template <class Key, class T, class Compare, class Alloc>
	void swap(ft::Map<Key, T, Compare, Alloc> &x, ft::Map<Key, T, Compare, Alloc> &y)
	{
		x.swap(y);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it = rhs.begin();
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it2 = lhs.begin();
		while (it != rhs.end())
		{
			if (*it != *it2)
				return (false);
			++it2;
			++it;
		}
		return (true);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return (true);
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it = lhs.begin();
		typename ft::Map<Key, T, Compare, Alloc>::const_iterator it2 = rhs.begin();
		while (it != lhs.end() && it2 != rhs.end())
		{
			if (*it > *it2)
				return (true);
			++it2;
			++it;
		}
		return (false);
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs) && !(lhs == rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs < rhs));
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const Map<Key, T, Compare, Alloc> &lhs, const Map<Key, T, Compare, Alloc> &rhs)
	{
		return (!(lhs > rhs));
	};
};

#endif