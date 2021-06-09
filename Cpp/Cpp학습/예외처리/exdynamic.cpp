#include <stdio.h>

class SomeClass {};

void calc1() throw(int)
{
	SomeClass obj;
	char* p = new char[1000];

	if (true)
	{
		throw 1;
	}
	delete[]p;
}

void sub15()
{
	try
	{
		calc1();
	}
	catch (int)
	{
		puts("정수형 예외 발생");
	}
}
