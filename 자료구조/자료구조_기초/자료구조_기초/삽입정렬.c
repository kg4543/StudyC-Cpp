//삽입정렬 : 두번째 자료부터 앞 자료를 비교하여 정렬한다.
#include <stdio.h>

void insertionSort(int* pary, int size);

void sub23()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	insertionSort(ary, size);

	int i;
	/*for ( i = 0; i < size; i++)
	{
		printf("%5d", ary[i]);
	}*/

	return 0;
}

void insertionSort(int* pary, int size)
{
	int i, j,k, temp;
	for (i = 1; i < size; i++)
	{
		for ( j = i; j > 0; j--) // 비교대상 전부터 0번까지 비교
		{
			if (pary[j] < pary[j-1]) //비교대상이 값이 크면 값 교체
			{
				temp = pary[j];
				pary[j] = pary[j-1];
				pary[j-1] = temp;
			}
		}
		for ( k = 0; k < size; k++)
		{
			printf("%5d", pary[k]);
		}
		printf("\n");
	}
}
