#include <stdio.h>

void divide2(int a, int b)
{
	try
	{
		if (b == 0)
		{
			throw "0으로 나눌수 없습니다.\n";
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