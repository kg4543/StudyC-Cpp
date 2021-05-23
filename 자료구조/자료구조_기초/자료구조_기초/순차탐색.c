#include <stdio.h>

int LinearSearch(int* pary, int size, int data);

void sub21()
{
	int ary[] = { 3, 5, 8, 2, 7, 6, 1 };
	int index; //검색 후 배열의 순번
	int size = sizeof(ary) / sizeof(ary[0]);
	int data = 8; // 검색값
	
	//검색
	index = LinearSearch(ary, size, data);

	//출력
	if (index == -1)
	{
		printf("찾을 수가 없습니다.");
	}
	else
	{
		printf("%d번째 값 : %d", index + 1, ary[index]);
	}

	return;
}

int LinearSearch(int* pary, int size, int data)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		if (data == pary[i])
		{
			return i; // 찾은 값의 순번
		}
	}
	return -1; // 값이 없을 경우
}