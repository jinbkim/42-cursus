#include "Brain.hpp"

// 해당 객체의 주소값을 반환하는 함수
const std::string	Brain::identify() const
{
	std::ostringstream	oss;

	std::cout<<"===== include brain.hpp =====\n";
	oss<<this;  // oss에 주소값인 문자열을 담음
	return (oss.str());  // 주소값을 문자열로 바꾼걸 반환
}
