#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question1(void) {

	printf("\n-------------\n");

	int a, b; // 계산할 값
	int c; //계산 방식
	int res; //계산 값
	int i = 1; //반복 실행

	while (i)
	{
		printf("첫번째(정수) 값을 입력하세요");
		scanf("%d", &a);
		printf("두번째(정수) 값을 입력하세요");
		scanf("%d", &b);
		printf("계산식을 입력하세요(1.더하기 2.빼기 3.곱하기 4.나누기 )");
		scanf("%d", &c);

		switch (c)
		{
		case 1:
			res = a + b;
			printf("%d\n", res);
			break;
		case 2:
			res = a - b;
			printf("%d\n", res);
			break;
		case 3:
			res = a * b;
			printf("%d\n", res);
			break;
		case 4:
			if (b != 0)
			{
				res = a / b;
				printf("몫: %d\n", res);
				printf("나머지: %d\n", a % b);
				break;
			}
			else {
				printf("나누는 값이 0입니다.\n");
			}
		default:
			printf("입력값을 다시 확인하세요.\n");
			break;
		}

		printf("종료하시려면 0, 다시 하시려면 1을 눌러주세요!!!");
		scanf("%d", &i);

		if (i==0)
		{
			i = 0;
		}
		else
		{
			i = 1;
		}
	}
	return 0;
}