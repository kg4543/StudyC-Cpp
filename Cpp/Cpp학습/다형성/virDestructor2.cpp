#include <stdio.h>

class Base
{
private:
	char* B_buf;

public:
	Base()
	{
		B_buf = new char[10]; 
		puts("Base ����");
	}
	virtual ~Base()
	{
		delete[] B_buf;
		puts("Bae �ı�");
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
		puts("����");
	}
	virtual ~Derived()
	{
		delete[] D_buf;
		puts("Derived �ı�");
	}
};

void sub12()
{
	Base* pB;

	pB = new Derived;
	delete pB;
}