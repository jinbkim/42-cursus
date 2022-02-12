// 템플릿을 써보는 문제
// 템플릿 : 함수나 클래스를 개별적으로 다시 작성하지 않아도, 여러 자료형으로 사용할수 있도록 하게 만들어 놓은 툴

#include "whatever.hpp"

// 이런 클래스의 객체가 들어와도 템플릿 함수는 제대로 작동함

// class Awesome
// {
//     public:
//         Awesome() : _n(0){}
//         Awesome(int n): _n(n){}
//         bool operator==( Awesome const & rhs ) { return (this->_n == rhs._n); }
//         bool operator!=( Awesome const & rhs ) { return (this->_n != rhs._n); }
//         bool operator>( Awesome const & rhs ) { return (this->_n > rhs._n); }
//         bool operator<( Awesome const & rhs ) { return (this->_n < rhs._n); }
//         bool operator>=( Awesome const & rhs ) { return (this->_n >= rhs._n); }
//         bool operator<=( Awesome const & rhs ) { return (this->_n <= rhs._n); }
//         int  getN() {return(_n);}
//     private:
//         int _n;
// };

int main(void)
{
    int a = 1;
    int b = 2;
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    swap(a, b);
    std::cout << "===== swap =====" << '\n';
    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    int minimum = ::min(a, b);
    std::cout << "min: " << minimum << '\n';
    int maximum = ::max(a, b);
    std::cout << "max: " << maximum << '\n';

	// std::cout << "\n================" << '\n';
    // Awesome j(20);
    // Awesome k(30);

    // std::cout << "j: " << j.getN() << '\n';
    // std::cout << "k: " << k.getN() << '\n';
    // swap(j, k);
    // std::cout << "===== swap =====" << '\n';
    // std::cout << "j: " << j.getN() << '\n';
    // std::cout << "k: " << k.getN() << '\n';
    // Awesome minAwesome = ::min(j, k);
    // std::cout << "min: " << minAwesome.getN() << '\n';
    // Awesome maxAwesome = ::max(j, k);
    // std::cout << "max: " << maxAwesome.getN() << '\n';
}