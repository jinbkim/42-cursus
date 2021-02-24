/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yechoi <yechoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 13:00:55 by yechoi            #+#    #+#             */
/*   Updated: 2020/11/30 18:08:52 by yechoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <string>

int main(int argc, char **argv)
{
    unsigned int n;
    
    if (argc != 2)
        return 0;
    try
    {
        n = atoi(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Invalid Argument." << '\n';
        return 0;
    }
    
    Array<int> integer(n);
    Array<double> dd(n);
    Array<char> character(n);
    Array<std::string> string(n);

    for (int i = 0; i < n; i++)
    {
        integer[i] = i + 1;
        dd[i] = i + 1.3;
        character[i] = static_cast<char>(i + 65);
        string[i] = "hello";
    }

    for (int i = 0; i < integer.size(); i++)
        std::cout << "integer[" << i << "]: " << integer[i] << std::endl;
    std::cout << "=======================" << std::endl;
    for (int i = 0; i < dd.size(); i++)
        std::cout << "double[" << i << "]: " << dd[i] << std::endl;
    std::cout << "=======================" << std::endl;
    for (int i = 0; i < character.size(); i++)
        std::cout << "character[" << i << "]: " << character[i] << std::endl;
     std::cout << "=======================" << std::endl;
    for (int i = 0; i < string.size(); i++)
        std::cout << "string[" << i << "]: " << string[i] << std::endl;

    std::cout << "======invalid inx======" << std::endl;
    try
    {
        std::cout << string[n] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    if (n > 0)
    {
        std::cout << "====change content====" << std::endl;
        std::cout << "now string[0] is \"bonjour\"" << std::endl;
        string[0] = "bonjour";
        for (int i = 0; i < string.size(); i++)
            std::cout << "string[" << i << "]: " << string[i] << std::endl;
    }
}