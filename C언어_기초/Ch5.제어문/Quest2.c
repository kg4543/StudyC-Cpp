#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int question2(void) {
	
	printf("\n-------------\n");

	int a; // 구구단 몇 단인지?
	int i; //반복문
	int q = 1; //전체반복
	while (q)
	{
		printf("구구단 몇단을 보고 싶은가요?");
		scanf("%d", &a);

		if (a > 0 && a <= 9)
		{
			for (i = 1; i <= 9; i++)
			{
				printf("%d * %d = %d\n", a, i, i * a);
			}
		}
		else
		{
			printf("0~9까지의 숫자 중 하나를 입력해주세요!!!");
		}

		printf("종료하시겠습니까?(종료: 0 / 계속 실행: 1)");
		scanf("%d", &q);
		if (q == 0)
		{
			break;
		}
		else 
		{
			q = 1;
		}
	}
	

	return 0;
}