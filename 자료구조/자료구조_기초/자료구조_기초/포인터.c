#include <stdio.h>

void sub4()
{
	int i = 10, j = 20;
	int* ptr;
	printf("\ni�� �� = %d \nj�� �� = %d", i, j);
	printf("\ni�� �޸� �ּ� (&i) = %u", &i);
	printf("\nj�� �޸� �ּ� (&j) = %u", &j);

	ptr = &i;
	printf("\n\n << ptr = &i ���� >>");
	printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr);
	printf("\n ptr�� ��(ptr) = %u", ptr);
	printf("\n ptr�� ������(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j ���� >>");
	printf("\n ptr�� �޸� �ּ�(&ptr) = %u", &ptr);
	printf("\n ptr�� ��(ptr) = %u", ptr);
	printf("\n ptr�� ������(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i = *ptr ���� >>");
	printf("\n i�� �� = %d", i);

	getchar();
}
