#include <stdio.h>

void divide(int a, int b)
{
	if (b == 0)
	{
		throw "0으로는 나눌 수 없습니다.";
	}
	printf("나누기 결과 %d 입니다.\n", a / b);
}

void sub02()
{
	try
	{
		divide(10, 5);
		divide(10, 0); // catch 문으로 이동
		divide(10, 5); // 실행되지 않음
	}
	catch (const char *message)
	{
		puts(message);
	}
}