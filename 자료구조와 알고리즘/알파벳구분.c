#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertionSort(int* pary, int size);

void main()
{
	char input_ary[10]; // 알파뱃 입력
	char* lower_ary, * upper_ary; // 대소문자 저장소 포인터
	upper_ary = (char*)malloc(sizeof(char)); //대문자 저장소 할당
	lower_ary = (char*)malloc(sizeof(char)); //소문자 저장소 할당

	int i = 0, j = 0, k = 0;
	printf("알파뱃을 입력하세요 : ");
	for ( i = 0; i < 10; i++)
	{
		scanf(" %c", &input_ary[i]); // 알파뱃 10자 입력
	}

	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]); //입력한 알파뱃 출력
	}

	int size = sizeof(input_ary) / sizeof(char);
	insertionSort(input_ary, size); // 알파뱃 삽입정렬
	
	printf("\n정렬 중...\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5c", input_ary[i]); //정렬 후 알파뱃 출력
	}

	for ( i = 0; i < 10; i++)
	{
		if (input_ary[i] >= 65 && input_ary[i] <= 90) // 대문자 찾기
		{
			upper_ary[j] = input_ary[i]; //대문자 저장소에 저장
			j++;
		}
		else if (input_ary[i] >= 97 && input_ary[i] <= 122) //소문자 찾기
		{
			lower_ary[k] = input_ary[i]; //소문자 저장소에 저장
			k++;
		}
		else
		{
			printf("알파벳이 아닙니다.\n"); //입력 값 예외 처리
		}
	}
	
	printf("\n대문자 : "); // 대문자가 없을 경우
	if (j == 0)
	{
		printf("대문자가 없습니다."); 
	}
	else
	{
		for (i = 0; i < j; i++) //대문자 출력 , j = 등록 횟수
		{
			printf("%5c", upper_ary[i]);
		}
	}
	

	printf("\n소문자 : "); 
	if (k == 0) //소문자가 없을 경우
	{
		printf("소문자가 없습니다.");
	}
	else 
	{
		for (i = 0; i < k; i++) //소문자 출력, k = 등록 횟수
		{
			printf("%5c", lower_ary[i]);
		}
	}
	
}

void insertionSort(char* pary, int size)
{
	int i, j;
	char temp;
	for (i = 1; i < size; i++)
	{
		for (j = i; j > 0; j--) //각 위치에서 0번까지 배열을 낮추면서 비교
		{
			if (pary[j] < pary[j - 1]) // 값이 작을 경우 제일 앞 0번과 교환
			{
				temp = pary[j];
				pary[j] = pary[j - 1];
				pary[j - 1] = temp;
			}
		}
	}
}