#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void fruit1(int count);

int sub7(void)
{

	printf("\n-------------\n");

	fruit1(1);

	return 0;
}

void fruit1(int count)
{
	printf("apple\n");
	if (count == 3)
	{
		return; // �ι�° fruit1()�Լ��� return
	}
	fruit1(count + 1);
	printf("jam\n");
}