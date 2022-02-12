#ifndef UTILS_HPP
# define UTILS_HPP

# include <utility>  // make_pair, etc..
# include <memory>  // allocator, etc..
# include <functional>  // less, etc.. 
# include <limits>  // numeric_limits, etc..

namespace ft
{
	template <typename T>
	void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};

	template <class T>
	struct Node
	{
		T data;
		Node *prev;
		Node *next;
	};

	template <class Key, class T>
	struct BNode
	{
		std::pair<Key, T> pair;
		BNode *left;
		BNode *right;
		BNode *parent;
		bool end;
	};

	template <bool B>
	struct enable_if
	{
	};

	template <>
	struct enable_if<true>
	{
		typedef int type;
	};

	template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral<bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<wchar_t>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral<long long>
	{
		static const bool value = true;
	};
};

#endif