#include <stdio.h>

void sub11()
{
	int i, sale[4] = { 157,209,251,315 };
	
	for ( i = 0; i < 4; i++)
	{
		printf("\n address : %u sale[%d] = %d", &sale[i],i, sale[i]);
	}

	printf("\n------------------\n");

	int n = 0, * ptr;
	int sale2[2][4] = { {63,84,141,130},
					   {157,203,251,312} };
	
	ptr = &sale2[0][0];
	for ( i = 0; i < 8; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	printf("\n------------------\n");

	int j;
	int(*pptr)[4] = &sale2[0][0];
	
	int* ppttr;
	ppttr = &sale2;

	printf("%u\n", ppttr);
	printf("%u\n", *ppttr);
	printf("%u\n", *(ppttr+7));


	for ( j = 0; j < 2; j++)
	{
		for (i = 0; i < 4; i++)
		{
			printf("\n address : %u sale %d = %d", pptr[i], i, (*pptr)[i]);
		}
		pptr++;
	}

	printf("\n------------------\n");

	int sale3[2][2][4] = { {
							{63,84,140,130},{157,209,251,312}
						  },
						  {
							{59,80,130,135},{149,184,239,310}
						  } 
						};

	ptr = &sale3[0][0][0];
	for (i = 0; i < 16; i++)
	{
		printf("\n address : %u sale %d = %d", ptr, i, *ptr);
		ptr++;
	}

	getchar();
}