#include <stdio.h>

int sub1()
{
	printf("\n-------------\n");

	int a;
	int *pa; // *: 별기능 없음 / 포인터 표시

	pa = &a; // a주소값 대입
	*pa = 10; // * : 주소의 데이터로 접근

	printf("포인터로 a 주소값 출력 : %d\n", pa);
	printf("포인터로 a 값 출력 : %d\n", *pa);
	
	printf("포인터로 a 주소값 출력 : %d\n", &a);
	printf("변수명으로 a값 출력 : %d\n", a);

	return 0;
}