#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub0(void)
{

	int a = 10;
	int* pi;
	int** ppi;
	int*** pppi;

	pi = &a;
	ppi = &pi;
	pppi = &ppi;

	printf("\n------------------------------------------------------\n");
	printf("변수  변수값   &연산      *연산    **연산      ***연산\n");
	printf("\n------------------------------------------------------\n");
	printf("a%10u%10d\n",&a,a);
	printf("pi%10u%10u%10u\n", pi, &pi, *pi);
	printf("ppi%10u%10u%10u%10u\n",ppi,&ppi,*ppi,**ppi);
	printf("pppi%10u%10u%10u%10u%10u\n", pppi, &pppi, *pppi, **pppi, ***pppi);
	

	return 0;
}