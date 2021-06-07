#include <stdio.h>

class Base
{
private:
	char* B_buf;

public:
	Base()
	{
		B_buf = new char[10]; 
		puts("Base »ý¼º");
	}
	virtual ~Base()
	{
		delete[] B_buf;
		puts("Bae ÆÄ±«");
	}
};

class Derived : public Base
{
private:
	int* D_buf;

public:
	Derived()
	{
		D_buf = new int[32];
		puts("¼º°ú");
	}
	virtual ~Derived()
	{
		delete[] D_buf;
		puts("Derived ÆÄ±«");
	}
};

void sub12()
{
	Base* pB;

	pB = new Derived;
	delete pB;
}