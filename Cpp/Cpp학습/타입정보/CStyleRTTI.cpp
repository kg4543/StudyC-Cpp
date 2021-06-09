#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Parent
{
public:
	char classname[32];
	Parent()
	{
		strcpy(classname, "Parent");
	}
	virtual void PrintMe()
	{
		printf("I am Parent");
	}
};

class Child : public Parent
{
private:
	int num;

public:
	Child(int anum) : num(anum)
	{
		strcpy(classname, "Child");
	}
	virtual void PrintMe()
	{
		printf("I am Child\n");
	}
	void PrintNum()
	{
		printf("Hello Child = %d\n", num);
	}
};

void func3(Parent* p)
{
	p->PrintMe();
	if (strcmp(p->classname,"Child") == 0)
	{
		((Child*)p)->PrintNum();
	}
	else
	{
		puts("이 객체는 num을 가지고 있지 않습니다.");
	}
}

void sub04()
{
	Parent p;
	Child c(5);

	func3(&c);
	func3(&p);
}