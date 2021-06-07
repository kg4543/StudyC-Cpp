#include <iostream>

class MyTest2
{
private:
	int x;
	int y;

public:
	MyTest2() {}
	MyTest2(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	~MyTest2()
	{
	}
	const MyTest2 operator +(const MyTest2 &other)
	{
		MyTest2 res;
		res.x = this->x + other.x;
		res.y = this->y + other.y;
		return res;
	}

	void printData()
	{
		printf("x : %d, y : %d\n", x, y);
	}
};

void sub06()
{
	MyTest2 obj1(10, 20);
	obj1.printData();
	MyTest2 obj2(20, 10);
	obj2.printData();

	printf("sum() ½ÇÇà...\n");
	MyTest2 obj;
	obj = obj1.operator+(obj2);
	obj.printData();

	return;
}