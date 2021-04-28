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

	printf("초기값 c= %d,d = %d\n", c, d); // 위에서 이미 증가한 상태여서 값이 동일
	printf("전위형: (++c)*3 = %d\n후위형: (d++)*3 = %d\n", pre, post); // 대입 시 전위는 1이 더 해진 상태 후위는 대입 후 1이 더 해짐

	return 0;
}