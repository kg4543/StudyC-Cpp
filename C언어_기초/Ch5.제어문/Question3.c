#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int plus(int, int);
int minus(int, int);
int multiple(int, int);
int divide(int, int);
int rest(int, int);
int while_exit();
int numcheck(char a[100]);

int question3(void) {

	printf("\n-------------\n");

	int i = 1; //전체 반복문

	while (i)
	{
		char a[100], b[100]; // 계산할 입력값
		int x, y; // 입력받은 문자를 상수로 변환할 값
		char c[100]; //계산 방식
		int res; //계산 값

		printf("첫번째(정수) 값을 입력하세요.");
		scanf("%s", a);
		x = numcheck(a);
		

		printf("두번째(정수) 값을 입력하세요.");
		scanf("%s", b);
		y = numcheck(b);
		

		printf("계산식을 입력하세요(1.더하기 2.빼기 3.곱하기 4.나누기 )");
		scanf(" %s", c);


		switch (c[0])
		{
		case '1':
			res = plus(x,y);
			printf("%d\n", res);
			break;
		case '2':
			res = minus(x, y);
			printf("%d\n", res);
			break;
		case '3':
			res = multiple(x, y);
			printf("%d\n", res);
			break;
		case '4':
			if (y != 0)
			{
				res = divide(x, y);
				int resc = rest(x, y);
				printf("몫: %d\n", res);
				printf("나머지: %d\n", resc);
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
		
		i = while_exit();
	}
	return 0;
}

int plus(int x, int y) 
{
	return x + y;
}

int minus(int x, int y)
{
	return x - y;
}

int multiple(int x, int y)
{
	return x * y;
}

int divide(int x, int y)
{
	return x / y;
}

int rest(int x, int y)
{
	return x % y;
}

int while_exit() 
{
	char j[10]; //종료 반복문

	while (1)
	{
		printf("종료하시려면 e, 다시 하시려면 c를 눌러주세요!!!");
		scanf(" %s", j);

		if (j[0] == 'e')
		{
			printf("종료하겠습니다.\n");
			return 0;
		}
		else if (j[0] == 'c')
		{
			printf("다시 실행하겠습니다.\n");
			return 1;
		}
		else
		{
			printf("잘못된 키입니다. 종료 하겠습니다.\n");
			return 1;
		}
	}
}

int numcheck(char a[100]) {

		if (atoi(a) || a == '0')
		{
			return atoi(a);
		}
		else 
		{
			printf("숫자를 입력하세요. 0으로 반환됩니다.\n");
			return 0;
		}
}