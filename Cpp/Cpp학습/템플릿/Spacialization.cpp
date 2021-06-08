#include <stdio.h>

template<class T>
void swap1(T& a, T& b)
{
	T t;
	t = a;
	a = b;
	b = t;
}

template<>void swap1<double>(double& a, double& b) // Ư��ȭ : Ư�� Ÿ��(double)���� �ٸ��� ����
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