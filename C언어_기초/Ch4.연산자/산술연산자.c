#include <stdio.h>

int sub0(void) {
	int a = 10, b = 20;
	int sum, sub, mul, inv;
	int res;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;
	
	printf("a�� ��: %d, b�� ��: %d\n", a, b);
	printf("����: %d\n", sum);
	printf("����: %d\n", sub);
	printf("����: %d\n", mul);
	printf("a�� ���� ����: %d\n", inv);

	a + b; // ���� ������� ������
	printf("%d + %d = %d\n", a, b, a + b); //���� �� �ٷ� ���
	res = a + b; // ���� ����� ������ ����
	printf("%d + %d = %d\n", a, b, res); //������ ���� �� ��� ���

	double apple;
	int banana;
	int orange;
	double peach;

	apple = 4.8 / 2.2;
	banana = 5 / 2;
	orange = 5 % 2;
	// peach = 4.8 % 2.3; �Ǽ��� ������ ����Ұ�

	printf("apple: %.1f\n", apple);
	printf("banana: %d\n", banana);
	printf("orange: %d\n", orange);

	return 0;
}