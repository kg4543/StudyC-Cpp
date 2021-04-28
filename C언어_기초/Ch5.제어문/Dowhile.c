#include <stdio.h>

int sub7(void) {

	printf("\n-------------\n");
	
	int a = 1;

	do {
		a = a * 2;
	} while (a < 10);

	printf("a : %d\n", a);

	return 0;
}