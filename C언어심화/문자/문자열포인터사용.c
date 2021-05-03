#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int sub7()
{
	printf("\n--------------\n");

	char* dessert = "apple";

	printf("오늘 후식은 %s입니다.\n", dessert);
	
	dessert = "banana";
	
	printf("내일 후식은 %s입니다.\n", dessert);

	return 0;
}