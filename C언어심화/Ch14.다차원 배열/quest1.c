#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int check_cha(char* ch, int chlen);

int question1()
{
	printf("\n--------------\n");

	///단어를 입력
	///단어의 길이 / 2 = 기준점
	///1번째 끝에 번째 비교해서 동일하면 회문
	
	char ch[80] = "";
	int check = 1;

	printf("문자열을 입력하세요 : ");
	scanf("%s", ch);
	int chlen = strlen(ch);
	printf("%d %s\n", chlen, ch);
	check = check_cha(ch, chlen);
	if (check == 1)
	{
		printf("회문이 아닙니다.");
	}
	else
	{
		printf("회문 입니다.");
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