#include <iostream>
using namespace std;

class Base
{
public:
	virtual void func1()
	{
		cout << "B:func1()" << endl;
	}
	virtual void func2()
	{
		cout << "B:func2()" << endl;
	}
	void func3()
	{
		cout << "B:func3()" << endl;
	}
};

class Drived : public Base
{
public:
	void func1()
	{
		cout << "D:func1()" << endl;
	}
	void func3()
	{
		cout << "D:func3()" << endl;
	}
	void func4()
	{
		cout << "D:func4()" << endl;
	}
};

void sub07()
{
	Base b;
	Drived d;
	Base* pb = new Drived;

	pb->func1();
	pb->func2();
	pb->func3();

	return;
}