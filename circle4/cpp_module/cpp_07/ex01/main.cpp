// 이문제도 템플릿을 사용해보는 문제
// 어떤 배열 or 어떤 함수가 들어와도 잘작동함

#include "iter.hpp"

int main(void)
{

    int arr1[2] = {1, 2};
    iter(arr1, 2, func);

    std::string arr2[3] = {"jinbkim", "hjung", "seobaek"};
    iter(arr2, 3, func);

    // int tab[] = { 0, 1, 2, 3, 4 };
    // iter(tab, 5, print);

	// Awesome tab2[5];
    // iter(tab2, 5, print);
    return 0;
}