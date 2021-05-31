#include <stdio.h>

void sub(int a) { printf("int: %d\n", a); }
void sub(int* a) { printf("pointer: %p\n", a); }

void sub14()
{
	int i = 1245, * pi = &i;

	sub(i);
	sub(pi);
	sub(NULL);
}