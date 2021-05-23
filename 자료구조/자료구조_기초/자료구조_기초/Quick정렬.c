#include <stdio.h>

void QuickSort(int*, int, int);

void sub26()
{
	int ary[] = { 3,5,2,4,7,6,1 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int i;

	for (i = 0; i < size; i++) // 처음 출력
	{
		printf("%5d", ary[i]);
	}

	printf("\n\n---------------정렬 중---------------\n\n");
	
	QuickSort(ary, 0, size - 1); // 베열과 처음, 마지막 지점을 가리키는 index 전달

	for (i = 0; i < size; i++) // 마지막 출력
	{
		printf("%5d", ary[i]);
	}
	printf("\n");

	

	return;
}

void QuickSort(int* pary, int left, int right)
{
	if (left + 1 >= right) //길이가 1 또는 2일 때 return
		return;

	int pivot = right / 2;  // 배열의 중간지점을 pivot으로 설정
	int mleft = left; // 처음 지점에서 점점 늘려가면서 pivot과 비교
	int mright = right; // 마지막 지점에서 점점 줄여가면서 pivot과 비교
	int temp; // 값을 swap하기 위한 저장소

	while (mleft <= mright)
	{
		while (pary[mleft] <= pary[pivot]) //처음 지점에서 중간값보다 큰 값이 나올 때까지 index++
			mleft++;
		while (pary[mright] >= pary[pivot]) //마지막 지점에서 중간값보다 작은 값이 나올 때까지 index--
			mright--;

		// 서로의 값(중간기준 좌,우 값)을 바꿔줌
		if (mleft <= mright) //mleft가 mright보다 클 경우 교체하지 않고 while문을 빠져나온다.
		{
			temp = pary[mleft];
			pary[mleft] = pary[mright];
			pary[mright] = temp;
		}
	}

	int i;
	for (i = 0; i < right+1; i++) // 중간 출력
	{
		printf("%5d", pary[i]);
	}
	printf("\n");

	QuickSort(pary, left, --mleft);
	QuickSort(pary, ++mright, right);
}