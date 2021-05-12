#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "use.h"

int test()
{
	int n1, n2;
	int result;
	input_data(&n1, &n2);
	result = sum(n1, n2);
	printf("гу : %d\n", result);

	return 0;
}