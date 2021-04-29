#include <stdio.h>

int sub5(void) {

	printf("\n-------------\n");

	int a = 1;

	while (a<10)
	{
		a = a * 2;
	}
	printf("a: %d\n", a);

	return 0;
}