// firend 선언문을 추가하여 아래 코드가 컴파일 되도록 하시오

// 예상 출력값
// Her phone number: 010-1234-5678
// His height: 170

#include <iostream>
#include <cstring>
using namespace std;

class Girl;

class Boy
{
private:
	int height;
public:
	Boy(int height) : height(height) {}
	void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
	char phNum[20];
public:
	Girl(const char * num)
	{
		strcpy(phNum, num);
	}
	void ShowYourFriendInfo(Boy &frn);
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
	cout<<"Her phone number: "<<frn.phNum<<endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
	cout<<"His height: "<<frn.height<<endl;
}

int main(void)
{
	Boy boy(170);
	Girl girl("010-1234-5678");

	boy.ShowYourFriendInfo(girl);
	girl.ShowYourFriendInfo(boy);
	return 0;
}