#include <stdio.h>

int a;
void assign10(void);
void assign20(void);

int sub2()
{
	printf("\n--------------\n");

	printf("�Լ� ȣ�� �� a �� : %d\n", a);

	assign10();
	assign20();

	printf("�Լ� ȣ�� �� a �� : %d\n", a); //a�� �������� 10�� ��ȯ
}

void assign10(void)
{
	a = 10;
}
void assign20(void)
{
	int a; // ���������� ����

	a = 20;
}