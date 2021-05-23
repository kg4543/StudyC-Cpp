#include <stdio.h>

BSearch(int* pary, int size, int data)
{
	int first = 0;
	int last = size - 1;
	int mid;
	while (first <= last)
	{
		mid = (first + last) / 2;
		if (data == pary[mid])
		{
			return mid;
		}
		else
		{
			if (data > pary[mid])
			{
				first = mid + 1;
			}
			else
			{
				last = mid - 1;
			}
		}
	}
	return -1;
}

void sub22()
{
	int ary[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int index;
	int data = 8;
	index = BSearch(ary, size,data);
	if (index == -1)
	{
		printf("탐색 실패!!!\n");
	}
	else
		printf("%d번째 값 : %d\n", index+1, ary[index]);

	return 0;
}