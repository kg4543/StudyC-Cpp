#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question2(void) {
	
	printf("\n-------------\n");

	int a; // ������ �� ������?
	int i; //�ݺ���
	int q = 1; //��ü�ݺ�
	while (q)
	{
		printf("������ ����� ���� ��������?");
		scanf("%d", &a);

		if (a > 0 && a <= 9)
		{
			for (i = 1; i <= 9; i++)
			{
				printf("%d * %d = %d\n", a, i, i * a);
			}
		}
		else
		{
			printf("0~9������ ���� �� �ϳ��� �Է����ּ���!!!");
		}

		printf("�����Ͻðڽ��ϱ�?(����: 0 / ��� ����: 1)");
		scanf("%d", &q);
		if (q == 0)
		{
			break;
		}
		else 
		{
			q = 1;
		}
	}
	

	return 0;
}