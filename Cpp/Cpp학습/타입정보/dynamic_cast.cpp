#include <iostream>

class A
{
public:
	virtual void test()
	{
		printf("A::test()\n");
	}
};
class B : public A
{
public:
	virtual void test()
	{
		printf("B::test()\n");
	}
	void test2()
	{
		printf("B::test2()\n");
	}
};
class C : public B
{
public:
	virtual void test()
	{
		printf("C::test()\n");
	}
	void test2()
	{
		printf("C::test2()\n");
	}
};

void GlobalFunc(A& a)
{
	try
	{
		C& c = dynamic_cast<C&>(a);
		printf("GlovalFunc()\n");
	}
	catch (std::bad_cast)
	{
		printf("casting error\n");
	}
}

void sub07()
{
	A* pac = new C;
	A* pab = new B;
	
	pac-> test();
	B* pb = dynamic_cast<B*>(pac);
	if (pb)
	{
		pb->test2();
	}

	C* pc = dynamic_cast<C*>(pab); // 자식은 부모를 가리킬 수 없다.
	if (pc)
	{
		pc->test2(); //실행안됨 : upcast
	}

	C c;
	GlobalFunc(c);
	B b;
	GlobalFunc(b);

	return;
}