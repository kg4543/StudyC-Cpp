#include <stdio.h>

template <typename T>
T cast(int s)
{
	return (T)s;
}

void sub05()
{
	unsigned u = cast<unsigned>(1234);
	double d = cast<double>(5678);

	printf("u = %d, d = %f\n", u, d);
}