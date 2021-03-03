/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 21:53:19 by yechoi            #+#    #+#             */
/*   Updated: 2020/12/01 21:53:19 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <string>
#include <iostream> 

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack() : std::stack<T, Container>() {}
        MutantStack(const MutantStack<T, Container>& ref)
            : std::stack<T, Container>(ref) {}
        MutantStack<T, Container>   &operator=(const MutantStack<T,Container> &ref)
        {
            if (this == &ref)
                return (*this);
            this->c = ref.c;
            return (*this);
        }
        virtual ~MutantStack() {}

        typedef typename std::stack<T,Container>::container_type::iterator iterator;
        typedef typename std::stack<T,Container>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T,Container>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T,Container>::container_type::const_reverse_iterator const_reverse_iterator;

        iterator                begin()
        {
            return (this->c.begin());
        }
        iterator                end(void)
        {
            return (this->c.end());
        }
        const_iterator          begin() const
        {
            return (this->c.begin());
        }
        const_iterator          end() const
        {
            return (this->c.end());
        }
        reverse_iterator        rbegin()
        {
            return (this->c.rbegin());
        }
        reverse_iterator        rend()
        {
            return (this->c.rend());
        }
        const_reverse_iterator  rbegin() const
        {
            return (this->c.rbegin());
        }
        const_reverse_iterator  rend() const
        {
            return (this->c.rend());
        }
};

#endif