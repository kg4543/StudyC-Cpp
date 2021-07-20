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

	pb->setData(10); // ���� Ŭ������ setdata()

	pd = static_cast<Derived*>(pb); //static_cast
	pd->setData(20); // �Ļ� Ŭ������ setdata()

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
static_cast : ��Ӱ����� ������ �� ���۷���, �⺻Ÿ��, Ÿ��üũ ����
dynamic_cast : ��Ӱ����� Ŭ���� ������ �� ���۷��� Ÿ��üũ,RTTI ��� �ʿ�
const_cast : const, volatile ���� �Ӽ� ����
reinterpret_cast : �����ͳ���, �����Ϳ� ��ġ�� ���� ��ȯ
*/