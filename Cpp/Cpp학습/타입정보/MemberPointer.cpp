#include <stdio.h>

class MyClass
{
public:
	int i, j;
	double d;
};

void sub08()
{
	MyClass C;
	int MyClass::* pi;
	double MyClass::* pd;
	int num;

	pi = &MyClass::i;
	pi = &MyClass::j;
	pd = &MyClass::d;
}