#include <stdio.h>

template <typename T>
void swap(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
}


void sub03()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	char e = 'e', f = 'f';

	swap(a, b);
	swap(c, d);
	swap(e, f);

	printf("a = %d, b= %d\n", a, b);
	printf("c = %.1f, d= %.1f\n", c, d);
	printf("e = %c, f= %c\n", e, f);
}