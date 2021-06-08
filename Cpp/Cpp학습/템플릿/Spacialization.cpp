#include <stdio.h>

template<class T>
void swap1(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

template<>void swap1<double>(double& a, double& b) // 특수화 : 특정 타입(double)에만 다르게 동작
{
	int i, j;

	i = (int)a;
	j = (int)b;
	a = a - i + j;
	b = b - j + i;
}

void sub13()
{
	double a = 1.2, b = 3.4;
	printf("a = %g, b = %g\n", a, b);
	swap1(a, b);
	printf("a = %g, b = %g\n", a, b);
}