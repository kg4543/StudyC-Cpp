#include <stdio.h>

class Parent
{
public:
	virtual void PrintMe() // virtual 객체의 자료형을 따른다.
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
	p->PrintMe(); //virtual로 선언
	((Child*)p)->PrintNum();
}

void sub01()
{
	Parent p;
	Child c(5);

	func(&c); // 자식을 선언 child.PrintMe
	func(&p);
}