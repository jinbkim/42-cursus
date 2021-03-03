#include "span.hpp"

// 생성자
Span::Span(unsigned int n) :_n(n)
{
}

// 복사생성자
Span::Span(const Span& ref) : _n(ref._n), _v(ref._v)
{
}

// 대입연산자 오버로딩
Span& Span::operator=(const Span& ref)
{
    if (this == &ref)
        return (*this);
    *this = Span(ref);
    return (*this);
}

// 소멸자
Span::~Span()
{
}



// 벡터 _v를 반환하는 함수
std::vector<int>    Span::getVector()
{
    return (_v);
}

// 벡터에 value를 넣는 함수
void                Span::addNumber(int value)
{
    if (_v.size() >= _n)  // 벡터 사이즈가 꽉차면
        throw Span::NoSpaceException();  // 자리가 없다고 말해줌
    _v.push_back(value);
}

template<typename InputIterator>
void Span::addNumber(InputIterator begin, InputIterator end)
{
	if (this->_v.size() + std::distance(begin, end) > this->_n)  // 벡터 사이즈가 꽉차면
        throw Span::NoSpaceException();  // 자리가 없다고 말해줌
	this->numbers.insert(begin, end);
}


// 백터안에있는 원소들중 2개를 뽑아 차이가 가장 큰값 구하기
unsigned int        Span::longestSpan()
{
    if (_v.size() < 2)  // 벡터 원소의 개수가 2개 미만이면
        throw Span::NoSpanException();  // span을 구할수 없다고 예외처리
    int min = *std::min_element(_v.begin(), _v.end());  // 최대값
    int max = *std::max_element(_v.begin(), _v.end());  // 최소값
    return (max - min);
}

// 백터안에있는 원소들중 2개를 뽑아 차이가 가장 작은값 구하기
unsigned int        Span::shortestSpan()
{
    if (_v.size() < 2)  // 벡터 원소의 개수가 2개 미만이면
        throw Span::NoSpanException();  // span을 구할수 없다고 예외처리
    std::vector<int> v(_v);  // _v벡터와 같은값을 가지는 v벡터 생성
    std::vector<int> span(_v.size());  // _v벡터와 같은 크기로 각 원소의 차이를 저장할 벡터 생성

    std::sort(v.begin(), v.end());  // 오름차순으로 정렬
	// adjacent_difference
	// template <class iter1, class iter2>
	// iter2 adjacent_difference (iter1 first, iter1 last, iter2 result);
	// 주어진 자료구조에서 [first, last) 범위 내 인접 원소들의 차이를 iterator인 result의 위치부터 저장하는 함수
    std::adjacent_difference(v.begin(), v.end(), span.begin());
    // 오름차순으로 정렬
	// span[0] 에는 v[0]의 값이 저장되어있음
	std::sort(span.begin()+1, span.end());
    return (span[1]);  // 제일 작은값 반환
}

const char* Span::NoSpaceException::what() const throw()
{
    return ("No Space Exception.");
}

const char* Span::NoSpanException::what() const throw()
{
    return ("No Span Exception.");
}