#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sub01()
{
	int a, b;

	try
	{
		printf("�������� ���� �Է��Ͻÿ� : ");
		scanf("%d", &a);
		if (a < 0)
		{
			throw a;
		}
		printf("������ ���� �Է��Ͻÿ� : ");
		scanf("%d", &b);
		if (b == 0)
		{
			throw "0���δ� ���� �� �����ϴ�.";
		}
		printf("������ ����� %d �������� %d�Դϴ�.\n", a / b, a % b);
	}
	catch (int a)
	{
		printf("%d�� �����̹Ƿ� ������ �ź�\n", a);
	}
	catch (const char* message)
	{
		puts(message);
	}
}