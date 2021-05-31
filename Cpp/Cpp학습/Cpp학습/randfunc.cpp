#include <stdio.h>
#include <stdlib.h>

inline int randfunc(int n)
{
	return rand() % n;
}

void main()
{
	int i, j, k;
	i = randfunc(10);
	j = randfunc(100);
	k = randfunc(50);
	printf("³­¼ö = %d,%d,%d\n", i, j, k);
}