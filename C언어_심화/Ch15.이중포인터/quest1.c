#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int plus(int, int);
int minus(int, int);
int multiple(int, int);
int divide(int, int);
int rest(int, int);
int while_exit();
int numcheck(char a[100]);
int fuc(int (*fp)(int, int));

int question1(void) {

	printf("\n-------------\n");

	int i = 1; //��ü �ݺ���

	while (i)
	{
		char a[100], b[100]; // ����� �Է°�
		int x, y; // �Է¹��� ���ڸ� ����� ��ȯ�� ��
		char c[100]; //��� ���
		int res; //��� ��

		printf("������ �Է��ϼ���(1.���ϱ� 2.���� 3.���ϱ� 4.������ )");
		scanf(" %s", c);


		switch (c[0])
		{
		case '1':
			res = fuc(plus);
			printf("����� : %d\n", res);
			break;
		case '2':
			res = fuc(minus);
			printf("����� : %d\n", res);
			break;
		case '3':
			res = fuc(multiple);
			printf("����� : %d\n", res);
			break;
		/*case '4':
			if (y != 0)
			{
				res = fuc(divide);
				printf("��: %d\n", res);
				res = fuc(rest);
				printf("������: %d\n", res);
				break;
			}
			else {
				printf("������ ���� 0�Դϴ�.\n");
				printf("�Է°��� �ٽ� Ȯ���ϼ���.\n");
				continue;
			}*/
		default:
			printf("���� �Է��� �ٽ� Ȯ���ϼ���.\n");
			continue;
		}

		i = while_exit();
	}
	return 0;
}

int fuc(int (*fp)(int, int))
{
	char a[100], b[100]; // ����� �Է°�
	int x , y ; // �Է¹��� ���ڸ� ����� ��ȯ�� ��
	int res; //��� ��

	printf("ù��°(����) ���� �Է��ϼ���.");
	scanf("%s", a);
	x = numcheck(a);


	printf("�ι�°(����) ���� �Է��ϼ���.");
	scanf("%s", b);
	y = numcheck(b);

	res = fp(x,y);
	return res;
}


int plus(int x, int y)
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}

int multiple(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

int rest(int x, int y)
{
	return x % y;
}

int while_exit()
{
	char j[10]; //���� �ݺ���

	while (1)
	{
		printf("�����Ͻ÷��� e, �ٽ� �Ͻ÷��� c�� �����ּ���!!!");
		scanf(" %s", j);

		if (j[0] == 'e')
		{
			printf("�����ϰڽ��ϴ�.\n");
			return 0;
		}
		else if (j[0] == 'c')
		{
			printf("�ٽ� �����ϰڽ��ϴ�.\n");
			return 1;
		}
		else
		{
			printf("�߸��� Ű�Դϴ�. ���� �ϰڽ��ϴ�.\n");
			return 1;
		}
	}
}

int numcheck(char a[100]) {

	if (atoi(a) || a == '0')
	{
		return atoi(a);
	}
	else
	{
		printf("���ڸ� �Է��ϼ���. 0���� ��ȯ�˴ϴ�.\n");
		return 0;
	}
}