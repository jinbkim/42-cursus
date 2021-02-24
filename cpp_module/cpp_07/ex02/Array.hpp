/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 10:44:04 by yechoi            #+#    #+#             */
/*   Updated: 2021/01/29 23:34:07 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        Array() : _element(nullptr), _n(0) {};
        Array(unsigned int n) : _element(new T[n]), _n(n) {};
        Array(const Array& ref)
        {
            *this = ref;
        };
        Array& operator=(const Array& ref)
        {
            if (this == &ref)
                return (*this);
            _n = ref.size();
            _element = new T[_n];
            for (int i = 0; i < _n; i++)
                _element[i] = ref._element[i];
            return (*this);
        };
        virtual ~Array()
        {
            delete []_element;
        };

        T& operator[](unsigned int idx)
        {
            if (idx < 0 || idx >= _n)
                throw OutofIndex();
            return (_element[idx]);
        };
        const T& operator[](unsigned int idx) const
        {
            if (idx < 0 || idx >= _n)
                throw OutofIndex();
            return (_element[idx]);
        };
        class OutofIndex : public std::exception
        {
            virtual const char* what() const throw()
            {
                return ("Out of Index.");
            };
        };
        unsigned int    size(void) {return(_n);};
};



#endif