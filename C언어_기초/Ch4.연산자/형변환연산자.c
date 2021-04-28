#include <stdio.h>

int sub4(void){

	printf("\n------------------------\n");

	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b); // 기본적으로 작은 size에서 큰 size로..,반대는 값이 잘릴 수 있다.
	printf("a = %d, b = %d\n", a, b);
	printf("a / b = %.1lf\n", res);

	a = (int)res; //좌항은 형변환 시킬 수가 없다.
	printf("(int) %.1f의 결과: %d\n", res, a );

	return 0;
}