#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>

void InputNameRef(char* &Name)
{
	Name = (char*)malloc(32);
	strcpy(Name, "Kim Goo Gyeom");
}

void sub10()
{
	char* Name;

	InputNameRef(Name);
	printf("이름은 %s입니다.\n", Name);
	free(Name);

	int a;
	int& ra = a;
	int* pa = &ra;
	printf("&a = %p, &ra = %p, pa = %p\n", &a, &ra, pa);
}