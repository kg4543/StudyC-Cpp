#include <stdio.h>

int sub1()
{
	printf("\n-------------\n");

	int a;
	int *pa; // *: ����� ���� / ������ ǥ��

	pa = &a; // a�ּҰ� ����
	*pa = 10; // * : �ּ��� �����ͷ� ����

	printf("�����ͷ� a �ּҰ� ��� : %d\n", pa);
	printf("�����ͷ� a �� ��� : %d\n", *pa);
	
	printf("�����ͷ� a �ּҰ� ��� : %d\n", &a);
	printf("���������� a�� ��� : %d\n", a);

	return 0;
}