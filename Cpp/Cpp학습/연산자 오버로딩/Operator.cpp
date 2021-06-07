#include <iostream>

class MyTest
{
private:
	int x;
	int y;

public:
	MyTest() {}
	MyTest(int x, int y)
	{
		this->x = x;
		this->y = y;
		printf("�μ� 2�� ������!!!\n");
		//printf("���� = x : %d, y : %d\n", this->x, this->y);
	}
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y)
	{
		printf("���� ������ ȣ��!!\n");
	}

	~MyTest()
	{
		//printf("�Ҹ� = x : %d, y : %d\n", this->x, this->y);
	}

	const MyTest sum(const MyTest& other) const // sum()�Լ��� ��� �� ��������ڸ� ȣ��
	{
		MyTest res;
		res.x = this->x + other.x;
		res.y = this->y + other.y;
		return res;
	}

	const MyTest& operator +(const MyTest& other) const
	{
		MyTest res;
		res.x = this->x + other.x;
		res.y = this->y + other.y;
		return res;
	}

	const MyTest& operator -(const MyTest& other) const
	{
		MyTest res;
		res.x = this->x - other.x;
		res.y = this->y - other.y;
		return res;
	}

	void printData()
	{
		printf("x : %d, y : %d\n",x,y);
	}
};

void main()
{
	MyTest obj1(10, 20);
	obj1.printData();
	MyTest obj2(20, 10);
	obj2.printData();
	
	MyTest obj;
	printf("sum() ����...\n");
	obj = obj1 + obj2;
	obj.printData();
	
	printf("minus() ����...\n");
	obj = obj1 - obj2;
	obj.printData();

	return;
}