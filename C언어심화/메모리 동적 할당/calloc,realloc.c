#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub2()
{
	printf("\n--------------\n");

	int* pi;
	int size = 5;
	int count = 0;

	int num;
	int i;
	
	pi = (int*)calloc(size, sizeof(int)); // 5���� �������(20byte) �Ҵ�
	//calloc : �Ҵ��� ��������� 0���� �ʱ�ȭ
	while (1)
	{
		printf("����� �Է��ϼ��� => ");
		scanf("%d", &num);
		if (num <= 0) 
		{
			break;
		}
		if (count == size)
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int)); 
			// �Է��� ������ ���� Ȯ���� ���ο� ��������� ����� �ּҸ� pi�� �Է� 
			//pi�� Null �߻� �� ó�� �����ͷ�;�޸� ������ �߻��� �� ����
			//realloc �Լ��� �Ҵ�� ũ�⸦ ����
			/*if (pi == NULL)
			{
				pi = pi_back;
			}*/
		}
		pi[count++] = num;
	}
	for ( i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi); // �Ҵ� ���� �ݳ�

	return 0;
}