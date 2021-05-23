 /*
 퀵 정렬 : 분할 정복 알고리즘
 정렬이 전혀 안되어 있으면 가장 빠름
 어느정도 정렬되어 있으면 삽입정렬이 더 빠름

 가운데 보다 크면 오른쪽 작은면 왼쪽 (반복)

 1. 원소들 중에서 pivot을 선택
 2. 이 pivot을 기준으로 앞에는 작은 값, 뒤에는 큰 값들을 위치시킨다.(분할)
 3. 분할된 작은 리스트를 재귀적으로 동작을 시킨다.(정복)
 4. 정렬된 작은 리스트들을 결합한다.(결합)
 */
#include <stdio.h>

void quickSort(int*, int, int);

void sub25()
{
	int ary[] = { 3,5,2,4,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int i;

	for (i = 0; i < size; i++) // 처음 출력
	{
		printf("%5d", ary[i]);
	}
	
	quickSort(ary, 0, size-1);
	printf("\n\n---------------정렬 중---------------\n\n");
	
	for (i = 0; i < size; i++) // 마지막 출력
	{
		printf("%5d", ary[i]);
	}
	printf("\n");

	return;
}

void quickSort(int* pary, int left, int right)
{
	if (left >= right)
		return;
	int pivot = left;
	int mleft = pivot + 1;
	int mright = right;
	int temp;
	int i;

	while (mleft <= mright) //mleft와 mright가 교체가 안 될때 까지
	{
		while (pary[mleft] <= pary[pivot])
			mleft++;
		while (pary[mright] >= pary[pivot] && mright > left)
			mright--;

		if (mleft > mright)
		{
			temp = pary[mright];
			pary[mright] = pary[pivot];
			pary[pivot] = temp;
		}
		else {
			temp = pary[mright];
			pary[mright] = pary[mleft];
			pary[mleft] = temp;
		}
	}

	quickSort(pary, left, mright - 1);
	quickSort(pary, mright + 1, right);
}