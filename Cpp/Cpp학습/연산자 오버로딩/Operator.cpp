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
		printf("인수 2개 생성자!!!\n");
		//printf("생성 = x : %d, y : %d\n", this->x, this->y);
	}
	MyTest(MyTest& rhs) : x(rhs.x), y(rhs.y)
	{
		printf("복사 생성자 호출!!\n");
	}

	~MyTest()
	{
		//printf("소멸 = x : %d, y : %d\n", this->x, this->y);
	}

	const MyTest sum(const MyTest& other) const // sum()함수를 사용 시 복사생성자를 호출
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
	printf("sum() 실행...\n");
	obj = obj1 + obj2;
	obj.printData();
	
	printf("minus() 실행...\n");
	obj = obj1 - obj2;
	obj.printData();

	return;
}