#include <stdio.h>

enum season { SPRING, SUMMER, FALL, WINTER };

int sub10()
{
	enum season ss;
	char* pc = NULL;

	ss = SPRING;
	switch (ss)
	{
	case SPRING:
		pc = "inline";
		break;
	case SUMMER:
		pc = "swinming";
		break;
	case FALL:
		pc = "trip";
		break;
	case WINTER:
		pc = "sking";
		break;
	}
	printf("계절 => %s\n", ss);
	printf("나의 레저활동 => %s\n", pc);

	// enum의 크기는 4바이트로 고정
	printf("%d\n", sizeof(ss));

	// 처음 0부터 1씩 증가
	// 중간에 숫자를 바꾸면 그 숫자부터 다시 1씩 증가
	printf("%d %d %d %d", SPRING, SUMMER, FALL, WINTER); // 0 1 2 3 


	return 0;
}