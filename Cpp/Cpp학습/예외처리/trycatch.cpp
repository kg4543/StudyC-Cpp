#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sub01()
{
	int a, b;

	try
	{
		printf("나누어질 수를 입력하시오 : ");
		scanf("%d", &a);
		if (a < 0)
		{
			throw a;
		}
		printf("나누는 수를 입력하시오 : ");
		scanf("%d", &b);
		if (b == 0)
		{
			throw "0으로는 나눌 수 없습니다.";
		}
		printf("나누는 결과는 %d 나머지는 %d입니다.\n", a / b, a % b);
	}
	catch (int a)
	{
		printf("%d는 음수이므로 나누기 거부\n", a);
	}
	catch (const char* message)
	{
		puts(message);
	}
}