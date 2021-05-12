#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* my_strcpy(char* pd, char* ps);

int sub19()
{
	printf("\n--------------\n");

	char str[80] = "strawberry";

	printf("바꾸기 전 문자열 : %s\n", str);

	my_strcpy(str, "apple");
	printf("바꾼 후 문자열 : %s\n", str);
	printf("다른 문자열 대입 : %s\n", my_strcpy(str,"kiwi"));

	return 0;
}

char* my_strcpy(char* pd, char* ps)
{
	char* po = pd;

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';

	return po;
}
