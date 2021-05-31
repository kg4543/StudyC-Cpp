#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int* pary, int size);

void main()
{
	char input_ary[10];
	char upper_ary[10];
	char lower_ary[10];
	char* pl = upper_ary, * pu = lower_ary;

	int i = 0, j = 0, k = 0;
	printf("알파뱃을 입력하세요 : ");
	for ( i = 0; i < 10; i++)
	{
		scanf(" %c", &input_ary[i]);
	}

	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]);
	}

	int size = sizeof(input_ary) / sizeof(char);
	insertionSort(input_ary, size);
	
	printf("\n정렬 중...\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]);
	}

	for ( i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90)
		{
			pu[j] = (char*)malloc(sizeof(char));
			pu[j] = input_ary[i];
			j++;
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122)
		{
			pl[k] = (char*)malloc(sizeof(char));
			pl[k] = input_ary[i];
			k++;
		}
		else
		{
			printf("알파벳이 아닙니다.\n");
		}
	}
	
	printf("\n대문자 : ");
	if (j == 0)
	{
		printf("대문자가 없습니다.");
	}
	else
	{
		for (i = 0; i < j; i++)
		{
			printf("%5c", pu[i]);
		}
	}
	

	printf("\n소문자 : ");
	if (k == 0)
	{
		printf("소문자가 없습니다.");
	}
	else 
	{
		for (i = 0; i < k; i++)
		{
			printf("%5c", pl[i]);
		}
	}
	
}

void insertionSort(char* pary, int size)
{
	int i, j;
	char temp;
	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--) //각 위치에서 0번까지 배열을 낮추면서 비교
		{
			if (pary[j] < pary[j - 1]) // 값이 작을 경우 앞으로 이동
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}