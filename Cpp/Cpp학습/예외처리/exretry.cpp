#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main()
{
	int num;

	try
	{
		printf("1에서 100사이의 정수를 입력하시오 : ");
		scanf("%d", &num);
		if (num < 1 || num > 100)
		{
			throw num;
		}
		printf("입력한 수 = %d\n", num);
	}
	catch (int num)
	{
		printf("%d는 1에서 100사이의 정수가 아닙니다.");
	}
}