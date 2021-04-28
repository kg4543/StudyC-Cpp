#include <stdio.h>

int sub6(void) {

	printf("\n------------------------\n");

	int a = 10, b = 20;
	int res = 2;

	a += 20;
	res += b + 10;

	printf("a = %d, b = %d\n",a,b);
	printf("res = %d\n", res);

	return 0;
}