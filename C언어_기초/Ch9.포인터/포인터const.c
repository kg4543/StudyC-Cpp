#include <stdio.h>

int sub3()
{
	printf("\n-------------\n");

	int a = 10, b = 20;
	const int* pa = &a; //������ ���� pa�� �����͸� �� �ٲ�� ��
	int* const pb = &b; //������ ���� pb�� �ּ��� ���� �Ұ�

	printf("���� a �� : %d\n", *pa);
	pa = &b;
	// pb = &a;
	printf("���� b �� : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("���� a �� : %d\n", *pa);
	// *pa = 30; const������ *pa ���� �Ұ�
	printf("���� a �� : %d\n", *pa);

	return 0;
}