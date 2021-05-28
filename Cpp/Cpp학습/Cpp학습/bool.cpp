#include <stdio.h>

int sub1()
{
	int age = 25;
	bool isAdult = age > 19;
	if (isAdult)
	{
		puts("성인입니다.");
	}

	return 0;
}