#include <stdio.h>

int sub9(void) {

	printf("\n------------------------\n");

	int a = 10, b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1);
	printf("a >> 2 : %d\n", a >> 2); 

	//제일 왼쪽 비트는 부호비트의 값을 따른다.
	char ch = 128; //0b 1000 0000
	unsigned char cha = 128;
	printf("ch >> 1 : %d\n", ch >> 1); //0b 1100 0000
	printf("cha >> 1 : %d\n", cha >> 1);

	return 0;
}