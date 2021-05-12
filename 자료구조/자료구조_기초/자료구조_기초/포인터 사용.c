#include <stdio.h>

void sub7()
{
	char* ptrArray[2];
	char** ptrptr;
	int i;

	ptrArray[0] = "Korea";
	ptrArray[1] = "Seoul";

	ptrptr = ptrArray;
	printf("\n ptrArray[0]의 주소 (&ptrArray[0]) = %u", &ptrArray[0]);
	printf("\n ptrArray[0]의 값 (ptrArray[0]) = %u", ptrArray[0]);
	printf("\n ptrArray[0]의 참조 값 (*ptrArray[0]) = %c", *ptrArray[0]);
	printf("\n ptrArray[0]의 참조 문자열 (*ptrArray) = %s", *ptrArray);

	printf("\n ptrArray[1]의 주소 (&ptrArray[1]) = %u", &ptrArray[1]);
	printf("\n ptrArray[1]의 값 (ptrArray[1]) = %u", ptrArray[1]);
	printf("\n ptrArray[1]의 참조 값 (*ptrArray[1]) = %c", *ptrArray[1]);
	printf("\n ptrArray[1]의 참조 문자열 (*ptrArray) = %s", *ptrArray);

	printf("\n ptrArray의 주소 (&ptrptr) = %u", &ptrptr);
	printf("\n ptrArray의 값 (ptrptr) = %u", ptrptr);
	printf("\n ptrArray의 1차 참조 값 (*ptrptr) = %u", *ptrptr);
	printf("\n ptrArray의 2차 참조 값 (**ptrptr) = %c", **ptrptr);
	printf("\n ptrArray의 2차 참조 문자열 (*ptrptr) = %s", *ptrptr);

	printf("\n\n *ptrArray[0] : ");
	for ( i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[0] + i));
	}
	printf("\n\n **ptrptr : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(*ptrptr + i));
	}

	printf("\n\n *ptrArray[1] : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(ptrArray[1] + i));
	}
	printf("\n\n **(ptrptr+1) : ");
	for (i = 0; i < 5; i++)
	{
		printf("%c", *(*(ptrptr +1) + i));
	}

}