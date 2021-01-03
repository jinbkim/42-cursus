#include "Brain.hpp"

const std::string	Brain::identify() const
{
	std::ostringstream	oss;

	oss<<this;  // oss에 주소값인 문자열을 담음
	return (oss.str());  // 주소값인 문자열 반환
}
