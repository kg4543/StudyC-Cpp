#include <stdio.h>

int sub4(void){

	printf("\n------------------------\n");

	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); // �⺻������ ���� size���� ū size��..,�ݴ�� ���� �߸� �� �ִ�.
	printf("a = %d, b = %d\n", a, b);
	printf("a / b = %.1lf\n", res);

	a = (int)res; //������ ����ȯ ��ų ���� ����.
	printf("(int) %.1f�� ���: %d\n", res, a );

	return 0;
}