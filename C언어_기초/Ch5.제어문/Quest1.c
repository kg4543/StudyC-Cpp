#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question1(void) {

	printf("\n-------------\n");

	int a, b; // ����� ��
	int c; //��� ���
	int res; //��� ��
	int i = 1; //�ݺ� ����

	while (i)
	{
		printf("ù��°(����) ���� �Է��ϼ���");
		scanf("%d", &a);
		printf("�ι�°(����) ���� �Է��ϼ���");
		scanf("%d", &b);
		printf("������ �Է��ϼ���(1.���ϱ� 2.���� 3.���ϱ� 4.������ )");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			res = a + b;
			printf("%d\n", res);
			break;
		case 2:
			res = a - b;
			printf("%d\n", res);
			break;
		case 3:
			res = a * b;
			printf("%d\n", res);
			break;
		case 4:
			if (b != 0)
			{
				res = a / b;
				printf("��: %d\n", res);
				printf("������: %d\n", a % b);
				break;
			}
			else {
				printf("������ ���� 0�Դϴ�.\n");
			}
		default:
			printf("�Է°��� �ٽ� Ȯ���ϼ���.\n");
			break;
		}

		printf("�����Ͻ÷��� 0, �ٽ� �Ͻ÷��� 1�� �����ּ���!!!");
		scanf("%d", &i);

		if (i==0)
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
	}
	return 0;
}