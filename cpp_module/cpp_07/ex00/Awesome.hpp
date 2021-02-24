/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 16:04:16 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/27 16:15:27 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
#define AWESOME_HPP

class Awesome
{
    public:
        Awesome() : _n(0){}
        Awesome(int n): _n(n){}
        bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
        bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
        bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
        bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
        bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
        bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
        int  getN() {return(_n);}
    private:
        int _n;
};

#endif