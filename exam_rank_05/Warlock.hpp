#include <iostream>

class Warlock
{
private:
	std::string name;
	std::string title;

	Warlock();  // name과 title없이 객체를 만들수 없도록 private으로 선언
	Warlock(Warlock const &other);  // 복사생성자로 객체를 만들수 없도록 private으로 선언
	Warlock &operator=(Warlock const &other);  // 대입연산자로 객체를 만들수 없도록 private으로 선언

public:
	Warlock(std::string const &name, std::string const &title);
	~Warlock();

	std::string const &getName() const;
	std::string const &getTitle() const;
	void setTitle(std::string const &title);
	void introduce() const;
};