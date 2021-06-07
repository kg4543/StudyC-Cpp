#include <stdio.h>

class Enemy
{
private:
	const int Speed;

public:
	Enemy(int aSpeed) : Speed(aSpeed) {} //매개변수 1개 : 변환생성자
	void Move()
	{
		printf("%d의 속도로 움직인다.\n", Speed);
	}
};

void sub16()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}