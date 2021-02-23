// c++의 형변환 연산자 static_cast를 사용해보는 문제
// 논리적으로 가능한 경우만 변환이 가능
// 들어오는 인자를 char, int, float, doulbe로 변환하는 문제

#include "Convert.hpp"

int     main(int argc, char** argv)
{
    double input;

    if (argc != 2)  // 인자가 1개가 아니면
        return 0;
    try
    {
        input = std::stof(argv[1]);  // 문자열을 실수로 변환
    }
    catch(const std::exception& e)  // 실수로 변환할수 없는 문자가 들어오면
    {
        std::cerr << "Invalid Argument" << std::endl;
        return 0;
    }

    Convert C(argv[1], input);
    try
    {
        C.toChar();  // char로 변환
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toInt();  // int로 변환
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toFloat();  // float로 변환
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        C.toDouble();  // double로 변환
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}