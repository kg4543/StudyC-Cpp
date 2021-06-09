#include <stdio.h>

class Parent
{
public:
	virtual void PrintMe() // virtual ��ü�� �ڷ����� ������.
	{
		printf("I am Parent\n");
	}
};

class Child : public Parent
{
private:
	int num;

public:
	Child(int anum) : num(anum) {}
	virtual void PrintMe()
	{
		printf("I am Child\n");
	}
	void PrintNum()
	{
		printf("Hello Child = %d\n", num);
	}
};

void func(Parent* p)
{
	p->PrintMe(); //virtual�� ����
	((Child*)p)->PrintNum();
}

void sub01()
{
	Parent p;
	Child c(5);

	func(&c); // �ڽ��� ���� child.PrintMe
	func(&p);
}