#include <stdio.h>

void sub4()
{
	int* ar, i;
	float* at;

	ar = new int[5];  // (int*)malloc(sizeof(int)*5)
	at = new float[100];
	
	for ( i = 0; i < 5; i++)
	{
		ar[i] = i+1;
	}
	for ( i = 0; i < 5; i++)
	{
		printf("%d번째 = %d\n", i + 1, ar[i]);
	}

	at[50] = 3.14f;
	printf("%d번째 값 : %.2f", 50, at[50]);

	delete[] ar, at;
}