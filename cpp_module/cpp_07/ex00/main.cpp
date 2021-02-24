/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 21:57:52 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/26 21:57:52 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include "Awesome.hpp"

int main(void)
{
    std::cout << "\033[1;31mINTEGER TEST\033[0m" << std::endl;
    int a = 7;
    int b = 10;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    ::swap(a, b);
    std::cout << "** after swap **" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    int minimum = ::min(a, b);
    std::cout << "min: " << minimum << std::endl;
    int maximum = ::max(a, b);
    std::cout << "max: " << maximum << std::endl;

    std::cout << "\033[1;31mFLOAT TEST\033[0m" << std::endl;
    float c = 7.3131;
    float d = 10.3131;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    ::swap(c, d);
    std::cout << "** after swap **" << std::endl;
    std::cout << "c: " << c << std::endl;
    std::cout << "d: " << d << std::endl;
    float min2 = ::min(c, d);
    std::cout << "min: " << min2 << std::endl;
    float max2 = ::max(c, d);
    std::cout << "max: " << max2 << std::endl;

    std::cout << "\033[1;31mCHAR TEST\033[0m" << std::endl;
    char e = 'e';
    char f = 'f';

    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
    ::swap(e, f);
    std::cout << "** after swap **" << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "f: " << f << std::endl;
    int min3 = ::min(e, f);
    std::cout << "min: " << static_cast<char>(min3) << std::endl;
    int max3 = ::max(e, f);
    std::cout << "max: " << static_cast<char>(max3) << std::endl;

    std::cout << "\033[1;31mSTRING TEST\033[0m" << std::endl;
    std::string h = "chaine1";
    std::string i = "chaine2";

    std::cout << "h: " << h << std::endl;
    std::cout << "i: " << i << std::endl;
    ::swap(h, i);
    std::cout << "** after swap **" << std::endl;
    std::cout << "h: " << h << std::endl;
    std::cout << "h: " << i << std::endl;
    std::string min4 = ::min(h, i);
    std::cout << "min: " << min4 << std::endl;
    std::string max4 = ::max(h, i);
    std::cout << "max: " << max4 << std::endl;

    std::cout << "\033[1;31mAWESOME TEST\033[0m" << std::endl;
    Awesome j(20);
    Awesome k(30);

    std::cout << "j: " << j.getN() << std::endl;
    std::cout << "k: " << k.getN() << std::endl;
    ::swap(j, k);
    std::cout << "** after swap **" << std::endl;
    std::cout << "j: " << j.getN() << std::endl;
    std::cout << "k: " << k.getN() << std::endl;
    Awesome min5 = ::min(j, k);
    std::cout << "min: " << min5.getN() << std::endl;
    Awesome max5 = ::max(j, k);
    std::cout << "max: " << max5.getN() << std::endl;
}