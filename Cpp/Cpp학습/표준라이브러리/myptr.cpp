#include <iostream>
#include <string>
using namespace std;

class CTest
{
public :
	CTest() { cout << "CTest()" << endl; };
	~CTest() { cout << "~CTest()" << endl; };
	void func() { cout << "func()" << endl; };
};

void sub10()
{
	shared_ptr<CTest> ptr1(new CTest);
	ptr1->func();
	cout << "count: " << ptr1.use_count() << endl;
	{
		shared_ptr<CTest>ptr2(ptr1);
		cout << "count: " << ptr1.use_count() << endl;
		ptr2->func();
		cout << "count: " << ptr1.use_count() << endl;
		shared_ptr<CTest>ptr3(ptr2);
		cout << "count: " << ptr1.use_count() << endl;
	}
	cout << "count: " << ptr1.use_count() << endl;
	ptr1->func();

	unique_ptr<CTest> uptr1(new CTest);
}