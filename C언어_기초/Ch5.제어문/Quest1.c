#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question1(void) {

	printf("\n-------------\n");
	int i = 1; //��ü �ݺ���

	while (i)
	{
		char a[10], b[10]; // ����� �Է°�
		int x, y; // �Է¹��� ���ڸ� ����� ��ȯ�� ��
		char c[10]; //��� ���
		int res; //��� ��
		char j[10]; //���� �ݺ���

		printf("ù��°(����) ���� �Է��ϼ���");
		scanf("%s", a);
		
		if (atoi(a))
		{
			x = atoi(a);
		}
		else {
			continue;
		}

		printf("�ι�°(����) ���� �Է��ϼ���");
		scanf("%s", b);
		
		if (atoi(b))
		{
			y = atoi(b);
		}
		else {
			continue;
		}

		printf("������ �Է��ϼ���(1.���ϱ� 2.���� 3.���ϱ� 4.������ )");
		scanf(" %s", c);


		switch (c[0])
		{
		case '1':
			res = x + y;
			printf("%d\n", res);
			break;
		case '2':
			res = x - y;
			printf("%d\n", res);
			break;
		case '3':
			res = x * y;
			printf("%d\n", res);
			break;
		case '4':
			if (y != 0)
			{
				res = x / y;
				printf("��: %d\n", res);
				printf("������: %d\n", x % y);
				break;
			}
			else {
				printf("������ ���� 0�Դϴ�.\n");
				printf("�Է°��� �ٽ� Ȯ���ϼ���.\n");
				continue;
			}
		default:
			printf("���� �Է��� �ٽ� Ȯ���ϼ���.\n");
			continue;
		}
		while (1)
		{
			printf("�����Ͻ÷��� e, �ٽ� �Ͻ÷��� c�� �����ּ���!!!");
			scanf(" %s", j);

			if (j[0] == 'e')
			{
				printf("�����ϰڽ��ϴ�.\n");
				i = 0;
				break;
				strtok(a, " ");
				strtok(b, " ");
			}
			else if (j[0] == 'c')
			{
				printf("�ٽ� �����ϰڽ��ϴ�.\n");
				i = 1;
				break;
			}
			else
			{
				printf("�� ���� Ű�Դϴ�. ���� �ϰڽ��ϴ�.\n");
				continue;
			}
		}
	}
	return 0;
}