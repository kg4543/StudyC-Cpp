#include <stdio.h>

void divide2(int a, int b)
{
	try
	{
		if (b == 0)
		{
			throw "0���� ������ �����ϴ�.\n";
			printf("%d\n", a / b);
		}
	}
	catch (const char* message)
	{
		puts(message);
	}
}

void sub12()
{
	divide2(20, 0);
}