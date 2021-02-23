#include <iostream>
using namespace std;

class a
{
public:
	int n;
	virtual void	func(void)
	{
		cout<<"hi!\n";
	}
};

class b : public a
{

};

class c: public a
{

};

int		main(void)
{
	a	*a1 = new a;
	a	*a2 = new b;
	b	*bb;
	c	*cc;
	// if ((bb = dynamic_cast<b*>(aa)))
	// 	cout<<"yes1\n";
	// else
	// 	cout<<"no1\n";

	if ((bb = dynamic_cast<b*>(a1)))
		cout<<"yes2\n";
	else
		cout<<"no2\n";
	
	if ((cc = dynamic_cast<c*>(a2)))
		cout<<"yes2\n";
	else
		cout<<"no2\n";
}