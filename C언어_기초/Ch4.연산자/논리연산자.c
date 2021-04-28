#include <stdio.h>

int sub3(void) {

	printf("\n------------------------\n");

	int a = 30;
	int res;

	res = (a > 10) && (a < 20); // 10<a<20 ±İÁö!
	printf("(a > 10) && (a < 20): %d\n", res);
	res = (a < 10) || (a > 20);
	printf("(a < 10) || (a > 20): %d\n", res);
	res = !(a >= 30);
	printf("! (a >= 30) : %d\n", res);

	return 0;
}