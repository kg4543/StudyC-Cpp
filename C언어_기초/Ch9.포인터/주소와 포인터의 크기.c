#include <stdio.h>

int sub4()
{
	printf("\n-------------\n");

	char ch;
	int in;
	double db;

	char* pc = &ch;
	int* pi = &in;
	double* pd = &db;

	printf("char형 변수의 주소 크기 : %d\n", sizeof(&ch));
	printf("int형 변수의 주소 크기 : %d\n", sizeof(&in));
	printf("double형 변수의 주소 크기 : %d\n", sizeof(&db));

	printf("char형 포인터의 크기 : %d\n", sizeof(pc));
	printf("int형 포인터의 크기 : %d\n", sizeof(pi));
	printf("double형 포인터의 크기 : %d\n", sizeof(pd));

	printf("char형 포인터가 가리키는 변수 크기 : %d\n", sizeof(*pc));
	printf("int형 포인터가 가리키는 변수 크기 : %d\n", sizeof(*pi));
	printf("double형 포인터가 가리키는 변수 크기 : %d\n", sizeof(*pd));

	return 0;
}