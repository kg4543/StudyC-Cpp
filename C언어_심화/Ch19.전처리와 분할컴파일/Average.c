#include <stdio.h>

int sub7()
{
	int a, b;
	double avg;
	input_d(&a,&b);
	avg = average(a, b);

	printf("avg : %.1lf\n", avg);
	return 0;
}