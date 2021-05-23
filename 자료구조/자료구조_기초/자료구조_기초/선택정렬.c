//선택정렬 : 0번방을 최소값이라고 가정하고 나머지 원소들과 비교하여 교체한다.
#include <stdio.h>

void SelectionSort(int* pary, int size);

void sub24()
{
	int ary[] = { 4, 2, 7, 5, 9, 1, 8, 3, 6 };
	int size = sizeof(ary) / sizeof(ary[0]);

	SelectionSort(ary, size);

	return 0;
}

void SelectionSort(int* pary, int size)
{
	int i, j, k, min, temp;
	for (i = 0; i < size - 1; i++)
	{
		min = i; // 제일 처음을 최소로 가정
		for (j = i + 1; j < size; j++) //2번째 값부터 비교 시작
		{
			if (pary[min] > pary[j]) // 만약 첫번째 값이 더 클 경우
			{
				min = j; // 최소를 변경
			}
		}
		temp = pary[min]; // 최소값의 자리 변경
		pary[min] = pary[i];
		pary[i] = temp;
		printf("\n%d 단계 : ", i + 1);
		for (k = 0; k < size; k++)
		{
			printf("%5d", pary[k]);
		}
	}
}