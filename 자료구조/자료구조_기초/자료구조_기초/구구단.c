#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sub1() 
{
	int i = 0, n;
	int multiple[9];

	while (1)
	{
		printf("\n1~9�� ������ �Է��ϼ��� : ");

		scanf("%d", &n);
		if (n < 0 || n > 9)
		{
			printf("�ٽ� Ȯ���ϼ���!!!"); 
		}
		else
		{
			printf("\n");
			for (i = 0; i < 9; i++)
			{
				multiple[i] = n * (i + 1);
				printf("%d * %d = %d \n", n, (i + 1), multiple[i]);
			}
		}
	}
	getchar();
}