#include <stdio.h>

void sub4()
{
	int i = 10, j = 20;
	int* ptr;
	printf("\ni의 값 = %d \nj의 값 = %d", i, j);
	printf("\ni의 메모리 주소 (&i) = %u", &i);
	printf("\nj의 메모리 주소 (&j) = %u", &j);

	ptr = &i;
	printf("\n\n << ptr = &i 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	ptr = &j;
	printf("\n\n << ptr = &j 실행 >>");
	printf("\n ptr의 메모리 주소(&ptr) = %u", &ptr);
	printf("\n ptr의 값(ptr) = %u", ptr);
	printf("\n ptr의 참조값(*ptr) = %d", *ptr);

	i = *ptr;
	printf("\n\n << i = *ptr 실행 >>");
	printf("\n i의 값 = %d", i);

	getchar();
}
