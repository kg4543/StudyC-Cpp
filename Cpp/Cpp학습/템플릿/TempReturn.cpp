#include <stdio.h>

template <typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

void sub04()
{
	int a = max(1, 2);
	double b = max(1.1, 2.2);
	int c = max<int>(2, 3.14);

	printf("c = %d", c);
}