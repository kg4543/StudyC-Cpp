#include <stdio.h>

void sub6()
{
	int i;
	char* ptrArray[4] = { {"Korea"}, {"Seoul"}, {"Mapo"}, {"152¹øÁö 2 / 3"} };
	for (i = 0;  i< 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	ptrArray[2] = "Jangno";
	printf("\n\n");
	for ( i = 0; i < 4; i++)
	{
		printf("\n %s", ptrArray[i]);
	}

	getchar();
}