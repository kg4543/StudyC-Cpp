#include <stdio.h>

int sub1(void) {

	printf("\n------------------------\n");
	
	int a = 10, b = 10;

	++a;
	b--;

	printf("a: %d\n", a);
	printf("b: %d\n", b);
	
	int c = 5, d = 5;
	int pre, post;

	pre = (++c) * 3;
	post = (d++) * 3;

	printf("�ʱⰪ c= %d,d = %d\n", c, d); // ������ �̹� ������ ���¿��� ���� ����
	printf("������: (++c)*3 = %d\n������: (d++)*3 = %d\n", pre, post); // ���� �� ������ 1�� �� ���� ���� ������ ���� �� 1�� �� ����

	return 0;
}