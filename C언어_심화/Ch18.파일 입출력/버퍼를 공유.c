#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub9()
{
	FILE* fp;
	int age;
	char name[20];

	fp = fopen("c.txt", "r");

	fscanf(fp, "%d", &age);
	//fgets(name, sizeof(name), fp);
	fscanf(fp, "%s", name);

	printf("나이 : %d, 이름: %s", age, name);
	fclose(fp);

	return 0;
}