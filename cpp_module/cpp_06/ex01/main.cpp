// 8크기의 랜덤 문자열(알파벳or숫자) + 랜덤 int형 변수+ 8크기의 랜덤 문자열(알파벳or숫자)
// 8+4+8 데이터로 직렬화하는 serialize함수 만들기

// 직렬화한 데이터를 역직렬화해서 데이터를 뽑아내는 deserialize 함수만들기

// c++의 형변환 연산자 static_cast를 사용해보는 문제
// 논리적으로 가능한 경우만 변환이 가능

// c++의 형변환 연산자 reinterpret_cast를 사용해보는 문제
// 포인터를 대상으로 하는, 그리고 포인터와 관련이 있는 모든 유형의 형 변환을 허용
// reinterpret_cast가 허용하는게 static_cast보다 큼

#include <string>
#include <iostream>

struct Data
{
    char	*s1;
    int		n;
	char	*s2;
};

// 8크기의 랜덤 문자열(알파벳or숫자) + 랜덤 int형 변수+ 8크기의 랜덤 문자열(알파벳or숫자)
// 데이터를 직렬화함
void    *serialize(void)
{
    char	*ptr;
    char	s1[8];
    char	s2[8];
    int		integer;
    char	alphanum[] = "0123456789abcdefghijklmnopqrstuvwxyz";

    srand(clock());  // 난수를 위해 사용하는 함수
    for (int i = 0; i < 7; i++)
    {
        s1[i] = alphanum[rand() % 35];  // 8크기의 랜덤 문자열(알파벳or숫자)
        s2[i] = alphanum[rand() % 35];  // 8크기의 랜덤 문자열(알파벳or숫자)
    }
	s1[7] = '\0';
	s2[7] = '\0';
    integer = rand();  // 랜덤 int형변수를 반환하는 함수
    ptr = new char[sizeof(s1) + sizeof(int) + sizeof(s2)];  // 문자열2개의 크기와 int형변수의 크기만큼 메모리 할당
	std::cout<<"s1 : "<<s1<<'\n';
	std::cout<<"integer : "<<integer<<'\n';
	std::cout<<"s2 : "<<s2<<'\n';
	
    memcpy(ptr, s1, 8);  // ptr = s1	
    memcpy(ptr + 8, &integer, 4);  // ptr = s1 + integer 
    memcpy(ptr + 12, s2, 8);  // ptr = s1 + integer + s2
    return (ptr);
}

// 데이터를 역직렬화함
Data    *deserialize(void *raw)
{
    Data *dd = new Data;

	// reinterpret_cast<char*>(raw) 해도됨
    dd->s1 = static_cast<char*>(raw);  // raw 가리키기
	// 8byte만큼 이동하기위해 먼저 static_cast<char*>(raw)
	// dd->n = *static_cast<int*>(static_cast<char*>(raw) + 8); // 에러
    dd->n = *reinterpret_cast<int*>(static_cast<char*>(raw) + 8);  // raw+8이후로 int 크기만큼 데이터 담기
    dd->s2 = static_cast<char*>(raw) + 12;  // raw+12 가리키기 

    return (dd);
}

int main(void)
{
	char    *ptr = static_cast<char*>(serialize());  // 랜덤데이터의 직렬화
    Data    *des = deserialize(ptr);  // 랜덤데이터를 역직렬화

    std::cout << des->s1 << std::endl;
    std::cout << des->n << std::endl;
    std::cout << des->s2 << std::endl;

    delete des;
}