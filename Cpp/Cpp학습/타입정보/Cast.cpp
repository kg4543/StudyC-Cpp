#include <iostream>
using namespace std;

class Base {
private:
	int data;

public:
	Base() {};
	~Base() {};
	void setData(int adata)
	{
		data = adata;
	}
	int getData()
	{
		return data;
	}
};

class Derived : public Base
{
public:
	void setData(int adata)
	{
		if (adata > 0)
		{
			adata = 0;
		}
		Base::setData(adata);
	}
	void printData()
	{
		cout << "printData() : " << getData() << endl;
	}
};

void sub06()
{
	Base* pb = new Derived;
	Derived* pd = NULL;

	pb->setData(10); // 기초 클래스의 setdata()

	pd = static_cast<Derived*>(pb); //static_cast
	pd->setData(20); // 파생 클래스의 setdata()

	pd->printData();

	char str[] = "string";
	const char* c1 = str;
	char* c2;
	const char str1[] = "hello Iot";

	c2 = const_cast<char*>(c1);
	c2[0] = 'a';

	char* c3 = const_cast<char*>(str1);
	c3[0] = 'H';

	puts(c2);
	puts(c3);

	int num = 10;
	const int& ref = num;
	int& rtem = const_cast<int&>(ref);
	rtem = 30;
	printf("%d\n", num);


	return;
}

/*
static_cast : 상속관계의 포인터 및 레퍼런스, 기본타입, 타입체크 안함
dynamic_cast : 상속관계의 클래스 포인터 및 레퍼런스 타입체크,RTTI 기능 필요
const_cast : const, volatile 등의 속성 변경
reinterpret_cast : 포인터끼리, 포인터와 수치형 간의 변환
*/