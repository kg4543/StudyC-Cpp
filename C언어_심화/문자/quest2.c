#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

void change_cha(char cha);

int question2()
{
	printf("\n--------------\n");

	char cha = ' ';

	printf("���ڸ� �Է��ϼ��� : ");
	scanf("%c", &cha);
	change_cha(cha);

	return 0;
}

void change_cha(char cha)
{
	char big;
	char small;
	int i = 1;
		if (cha >= 65 && cha <= 90)
		{
			small = cha + ('a' - 'A');
			printf("%c", small);
			i = 0;
		}
		else if (cha >= 97 && cha <= 122)
		{
			big = cha - ('a' - 'A');
			printf("%c", big);
			i = 0;
		}
		else
		{
			printf("�����ڸ� �Է��ϼ���!!!\n");
			getchar();
			scanf("%c",&cha);
			change_cha(cha);
		}
}
