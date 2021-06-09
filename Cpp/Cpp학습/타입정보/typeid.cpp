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
	virtual void PrintMe()
	{
		printf("I am Child\n");
	}
	void PrintNum()
	{
		printf("Hello Child = %d\n", num);
	}
};

void func1() {}

void sub02()
{
	Parent P, * pP;
	Child C(123), * pC;
	pP = &P;
	pC = &C;

	printf("P=%s, pP=%s, *pP=%s\n", typeid(P).name(), typeid(pP).name(), typeid(*pP).name());
	printf("C=%s, pC=%s, *pC=%s\n", typeid(C).name(), typeid(pC).name(), typeid(*pC).name());

	pP = &C;
	printf("pP=%s, *pP=%s\n", typeid(pP).name(), typeid(*pP).name());
	printf("P_Hash_code = %u\n", typeid(P).hash_code());
	printf("func = %s\n", typeid(func1).name());

}