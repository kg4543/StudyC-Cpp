#include <stdio.h>
#include <typeinfo>

class Parent
{
public:
	virtual void PrintMe()
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
	virtual void PrintMe() { printf("I am Child\n"); }
	void PrintNum() { printf("Hello Child = %d\n", num); }
};

void func2(Parent* p)
{
	p->PrintMe();
	if (typeid(*p) == typeid(Child))
	{
		((Child*)p)->PrintNum();
	}
	else
	{
		puts("이 객체는 num을 가지고 있지 않습니다.");
	}
}

void sub03()
{
	Parent p;
	Child c(5);

	func2(&c);
	func2(&p);
}