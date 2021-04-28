#include <stdio.h>

int sub0(void) {
	int a = 10, b = 20;
	int sum, sub, mul, inv;
	int res;
	sum = a + b;
	sub = a - b;
	mul = a * b;
	inv = -a;
	
	printf("a의 값: %d, b의 값: %d\n", a, b);
	printf("덧셈: %d\n", sum);
	printf("뺄셈: %d\n", sub);
	printf("곱셈: %d\n", mul);
	printf("a의 음수 연산: %d\n", inv);

	a + b; // 연산 결과값이 버려짐
	printf("%d + %d = %d\n", a, b, a + b); //연산 후 바로 출력
	res = a + b; // 연산 결과를 변수에 저장
	printf("%d + %d = %d\n", a, b, res); //변수에 저장 후 계속 사용

	double apple;
	int banana;
	int orange;
	double peach;

	apple = 4.8 / 2.2;
	banana = 5 / 2;
	orange = 5 % 2;
	// peach = 4.8 % 2.3; 실수는 나머지 연산불가

	printf("apple: %.1f\n", apple);
	printf("banana: %d\n", banana);
	printf("orange: %d\n", orange);

	return 0;
}