#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int check_cha(char* ch, int chlen);

int question1()
{
	printf("\n--------------\n");

	///�ܾ �Է�
	///�ܾ��� ���� / 2 = ������
	///1��° ���� ��° ���ؼ� �����ϸ� ȸ��
	
	char ch[80] = "";
	int check = 1;

	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", ch);
	int chlen = strlen(ch);
	printf("%d %s\n", chlen, ch);
	check = check_cha(ch, chlen);
	if (check == 1)
	{
		printf("ȸ���� �ƴմϴ�.");
	}
	else
	{
		printf("ȸ�� �Դϴ�.");
	}
}

int check_cha(char* ch, int chlen)
{
	int i;
	for ( i = 0; i < chlen/2; i++)
	{
		if (ch[i] != ch[chlen-i-1])
		{
			return 1;
		}
	}
	return 0;
}