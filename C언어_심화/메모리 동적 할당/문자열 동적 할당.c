#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** ps);

int sub4()
{
	printf("\n--------------\n");

	char temp[80];
	char* str[21] = { 0 };
	int i = 0;

	while (i < 20)
	{
		printf("���ڿ��� �Է��ϼ��� : ");
		gets(temp);
		if (strcmp(temp, "end") == 0)
		{
			break;
		}
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
		i++;
	}
	print_str(str); //������ �迭�� ���� ����Ʈ�� �޾Ƽ� ���

	for (i = 0; str[i] != NULL; i++)
	{
		free(str[i]);
	}

	return 0;
}

void print_str(char** ps) //������ �迭�� ���� ����Ʈ�� �޾Ƽ� ���
{
	while (*ps != NULL)
	{
		printf("%s\n", *ps);
		ps++;
	}
}