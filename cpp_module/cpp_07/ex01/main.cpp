/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 22:56:05 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/26 22:56:05 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    char arr1[3] = {'a', 'b', 'c'};
    iter(arr1, 3, func);

    int arr2[3] = {2, 4, 6};
    iter(arr2, 3, func);

    std::string arr3[3] = {"yeji", "jihyun", "zuno"};
    iter(arr3, 3, func);

    int tab[] = { 0, 1, 2, 3, 4 };
    Awesome tab2[5];
    iter(tab, 5, print);
    iter(tab2, 5, print);
    return 0;
}