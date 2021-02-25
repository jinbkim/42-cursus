#ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

// class Awesome
// {
//     public:
//         Awesome( void ) : _n( 42 ) { return; }
//         int get( void ) const { return this->_n; }
//     private:
//         int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//     o << rhs.get();
//     return o;
// }

// template< typename T >
// void print( T const & x )
// {
//     std::cout << x << '\n';
//     return;
// }

template <typename T>
void    func(T const &name)
{
    std::cout <<"my name is " << name << std::endl;
}

template <typename T>
void    iter(T *array, int len, void (*f)(T const &ref))
{
    for (int i = 0; i < len; i++)
        f(array[i]);
}

#endif