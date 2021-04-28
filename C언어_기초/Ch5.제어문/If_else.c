#include <stdio.h>

int sub1(void) {
	
	printf("\n-------------\n");
	
	int a = 10;
	
	if (a >= 0)
	{
		a = 1;
	}
	else {
		a = -1;
	}

	printf("a: %d\n",a);

	return 0;
}