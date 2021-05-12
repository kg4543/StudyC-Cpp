#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sub2()
{
	printf("\n--------------\n");

	int* pi;
	int size = 5;
	int count = 0;

	int num;
	int i;
	
	pi = (int*)calloc(size, sizeof(int)); // 5개의 저장공간(20byte) 할당
	//calloc : 할당한 저장공간을 0으로 초기화
	while (1)
	{
		printf("양수만 입력하세요 => ");
		scanf("%d", &num);
		if (num <= 0) 
		{
			break;
		}
		if (count == size)
		{
			size += 5;
			pi = (int*)realloc(pi, size * sizeof(int)); 
			// 입력이 많아질 수록 확장한 새로운 저장공간을 만들어 주소를 pi에 입력 
			//pi가 Null 발생 시 처음 포인터로;메모리 누수가 발생할 수 있음
			//realloc 함수는 할당된 크기를 조절
			/*if (pi == NULL)
			{
				pi = pi_back;
			}*/
		}
		pi[count++] = num;
	}
	for ( i = 0; i < count; i++)
	{
		printf("%5d", pi[i]);
	}
	free(pi); // 할당 공간 반납

	return 0;
}