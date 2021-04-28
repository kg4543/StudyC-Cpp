#include <stdio.h>

int sub3(void) {

	printf("\n-------------\n");

	int a = 20, b = 10;

	// 여러번 if문 하는 것보다 중복 if문이 효율이 좋음
	if (a>10)
	{
		if (b>=0)
		{
			b = 1;
		}
		else
		{
			b = -1;
		}
	}
	
	printf("a : %d, b : %d\n", a, b);

	printf("\n-------------\n");

	int c = 10, d = 20;

	if (c<0)
	{
		if (d>0)
		{
			printf("ok");
		}
	}
	else {
		printf("ok");
	}

	return 0;
}