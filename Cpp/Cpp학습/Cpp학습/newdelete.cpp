#include <stdio.h>

int sub3()
{
	int* pi, * pj;

	pi = new int;
	pj = new int(10); // �����ڸ� ȣ���ϴ� ������������ �ٷ� �ʱ�ȭ�� �����ϴ�.
	*pi = 123;
	printf("*pi = %d\n", *pi);
	printf("*pj = %d\n", *pj);
	delete pi, pj;

	return 0;
}