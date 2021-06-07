#include <stdio.h>

class StaticTest2 {
	static int a;
	int b;

public:
	StaticTest2();
	static void setData(int);
	void getData();
};

int StaticTest2::a = 10;

StaticTest2::StaticTest2()
{
	this->b = 20;
}

void StaticTest2::getData()
{
	printf("a: %d, b : %d\n",a, b);
}

void StaticTest2::setData(int aa)
{
	a = aa; //static������ this ����� �ȵ� (a�� ��ü�� �Ӽ������Ͱ� �ƴ�)
}

void sub11()
{
	StaticTest2 s1;
	s1.getData();
	StaticTest2 s2;
	s2.getData();

	s1.setData(30);
	s1.getData();

	s2.getData();

	StaticTest2::setData(40);
	s1.getData();
	s2.getData();

	return;
}