/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:57:55 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/26 21:57:55 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>
#include "Awesome.hpp"

template <typename T>
void    swap(T& A, T &B)
{
    T   temp;

    temp = A;
    A = B;
    B = temp;
}

template <typename T>
T       &min(T& A, T& B)
{
    if (A >= B)
        return (B);
    return (A);
}

template <typename T>
T       &max(T& A, T& B)
{
    if (A <= B)
        return (B);
    return (A);
}

#endif