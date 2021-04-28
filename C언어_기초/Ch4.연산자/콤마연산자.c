#include <stdio.h>

int sub7(void) {

	printf("\n------------------------\n");

	int a = 10, b = 20;
	int res;

	res = (++a, ++b);

	printf("a: %d, b: %d\n", a, b);
	printf("res: %d\n", res);

	return 0;
}