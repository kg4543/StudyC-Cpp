#include <stdio.h>

void divide(int a, int b)
{
	if (b == 0)
	{
		throw "0���δ� ���� �� �����ϴ�.";
	}
	printf("������ ��� %d �Դϴ�.\n", a / b);
}

void sub02()
{
	try
	{
		divide(10, 5);
		divide(10, 0); // catch ������ �̵�
		divide(10, 5); // ������� ����
	}
	catch (const char *message)
	{
		puts(message);
	}
}