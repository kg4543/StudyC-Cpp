#include <stdio.h>

void sub2()
{
	int i, length = 0;
	char str[50];
	printf("문자열을 입력하세요 : ");
	gets(str);
	printf("입력된 문자열은 \n \"");
	for (i = 0; str[i]; i++)
	{
		printf("%c", str[i]);
		length += 1;
	}
	printf("\" \n입니다.");
	printf("\n\n 입력된 문자열의 길이 = %d \n", length);

	getchar();
}