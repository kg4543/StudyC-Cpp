#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub6()
{
	printf("\n--------------\n");

	printf("apple이 저장된 시작 주소 값 : %p\n", "apple");
	printf("두 번째 문자의 주소 값 : %p\n", "apple" + 1);
	printf("첫 번째 문자 : %c\n", *"apple");
	printf("두 번째 문자 : %c\n", *("apple" + 1));
	printf("배열로 표현한 세 번째 문자 : %c\n", "apple"[2]);

	return 0;
}