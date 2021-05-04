#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void input_lotto(int* pl, int size);
void print_lotto(int* pl, int size);

int question1()
{
	printf("\n--------------\n");

	int lotto[6];
	int size = (sizeof(lotto)/sizeof(lotto[0]));

	input_lotto(lotto,size);

	print_lotto(lotto, size);

	return;
}

void input_lotto(int* pl,int size)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		scanf("%d", &pl[i]);

		if (pl[i] <= 0 || pl[i] > 45)
		{
			printf("범위를 벗어났습니다.\n45이하의 값을 입력하세요!!\n");
			i--;
		}
		for (j = 0; j < i; j++)
		{
				if (pl[i] == pl[j])
				{
					printf("동일한 값을 입력하셨습니다.\n다른 값을 입력하세요!!\n");
					i--;
					break;
				}
		}
	}
}

void print_lotto(int* pl, int size)
{
	int i;
	for ( i = 0; i < size; i++)
	{
		printf("%d ", pl[i]);
	}
}