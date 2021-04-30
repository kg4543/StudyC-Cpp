#include<stdio.h>

int sub6(void)
{
	printf("\n-------------\n");

	char str[80];
	printf("문자열 입력 : ");
	gets(str); //빈칸을 포함한 문자열 입력
	puts("입력된 문자열 : "); //자동으로 개행을 시켜준다. 문자열만 출력하기 때문에 printf보다 빠름
	puts(str); //문자열 출력

	return 0;
}