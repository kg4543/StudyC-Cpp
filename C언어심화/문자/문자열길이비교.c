#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sub17()
{
	printf("\n--------------\n");

	char str1[80], str2[80];
	char* resp;

	printf("2���� ���� �̸� �Է� : ");
	scanf("%s%s", str1, str2);
	if (strlen(str1)>strlen(str2))
	{
		resp = str1;
		printf("�̸��� �� ������ : %s\n", resp);
	}
	else if (strlen(str1) < strlen(str2)) // strlen : ���ڿ� ����
	{
		resp = str2;
		printf("�̸��� �� ������ : %s\n", resp);
	}
	else
	{
		printf("���̰� �����մϴ�.");
	}

	return 0;
}