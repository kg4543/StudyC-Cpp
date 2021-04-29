#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question1(void) {

	printf("\n-------------\n");
	int i = 1; //전체 반복문

	while (i)
	{
		char a[10], b[10]; // 계산할 입력값
		int x, y; // 입력받은 문자를 상수로 변환할 값
		char c[10]; //계산 방식
		int res; //계산 값
		char j[10]; //종료 반복문

		printf("첫번째(정수) 값을 입력하세요");
		scanf("%s", a);
		
		if (atoi(a))
		{
			x = atoi(a);
		}
		else {
			continue;
		}

		printf("두번째(정수) 값을 입력하세요");
		scanf("%s", b);
		
		if (atoi(b))
		{
			y = atoi(b);
		}
		else {
			continue;
		}

		printf("계산식을 입력하세요(1.더하기 2.빼기 3.곱하기 4.나누기 )");
		scanf(" %s", c);


		switch (c[0])
		{
		case '1':
			res = x + y;
			printf("%d\n", res);
			break;
		case '2':
			res = x - y;
			printf("%d\n", res);
			break;
		case '3':
			res = x * y;
			printf("%d\n", res);
			break;
		case '4':
			if (y != 0)
			{
				res = x / y;
				printf("몫: %d\n", res);
				printf("나머지: %d\n", x % y);
				break;
			}
			else {
				printf("나누는 값이 0입니다.\n");
				printf("입력값을 다시 확인하세요.\n");
				continue;
			}
		default:
			printf("계산식 입력을 다시 확인하세요.\n");
			continue;
		}
		while (1)
		{
			printf("종료하시려면 e, 다시 하시려면 c를 눌러주세요!!!");
			scanf(" %s", j);

			if (j[0] == 'e')
			{
				printf("종료하겠습니다.\n");
				i = 0;
				break;
				strtok(a, " ");
				strtok(b, " ");
			}
			else if (j[0] == 'c')
			{
				printf("다시 실행하겠습니다.\n");
				i = 1;
				break;
			}
			else
			{
				printf("잘 못된 키입니다. 종료 하겠습니다.\n");
				continue;
			}
		}
	}
	return 0;
}