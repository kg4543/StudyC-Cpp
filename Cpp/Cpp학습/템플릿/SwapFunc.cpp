#include <stdio.h>

void swap(int& a, int& b)
{
	int t;
	t = a;
	a = b;
	b = t;
}
void swap(double& a, double& b)
{
	double t;
	t = a;
	a = b;
	b = t;
}

void sub01()
{
	int a = 3, b = 4;
	double c = 1.2, d = 3.4;
	swap(a, b);
	swap(c, d);
	printf("a = %d, b= %d\n", a, b);
	printf("c = %.1f, d= %.1f\n", c, d);
}