#include <stdio.h>

class Enemy
{
private:
	const int Speed;

public:
	Enemy(int aSpeed) : Speed(aSpeed) {} //�Ű����� 1�� : ��ȯ������
	void Move()
	{
		printf("%d�� �ӵ��� �����δ�.\n", Speed);
	}
};

void sub16()
{
	Enemy e1(10), e2(20);
	e1.Move();
	e2.Move();
}