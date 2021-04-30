#include <stdio.h>

int sub3()
{
	printf("\n-------------\n");

	int a = 10, b = 20;
	const int* pa = &a; //포인터 변수 pa로 데이터를 못 바뀌게 함
	int* const pb = &b; //포인터 변수 pb의 주소지 변경 불가

	printf("변수 a 값 : %d\n", *pa);
	pa = &b;
	// pb = &a;
	printf("변수 b 값 : %d\n", *pa);
	pa = &a;
	a = 20;
	printf("변수 a 값 : %d\n", *pa);
	// *pa = 30; const때문에 *pa 변경 불가
	printf("변수 a 값 : %d\n", *pa);

	return 0;
}