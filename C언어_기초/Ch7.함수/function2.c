#include <stdio.h>

//int function2(int, int);

int sub2(void) 
{

	printf("\n-------------\n");

	int a = 10, b = 20;
	int res;
	
	res = function2(a, b);
	printf("result : %d\n",res);

	return 0;
}

int function2(int x, int y) 
{
	int res;
	res = x + y;
	return res;
}