#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	int num;
	char name[20];
	char* pname;

	double weight;
}Fitness;

int input_data(Fitness** pary, int total)
{
	int i = total; // 전체 맴버 수 이후부터 다시 등록
	while (1)
	{
		pary[i] = (Fitness*)malloc(sizeof(Fitness)); // 회원 정보를 등록할 때 마다 동적할당
		printf("회원 번호 : ");
		scanf("%d", &pary[i]->num); // 음수일 경우 탈출
		if (pary[i]->num < 0)
		{
			free(pary[i]);
			break;
		}
		printf("회원 이름 : ");
		scanf("%s", &pary[i]->name);

		printf("회원 체중 : ");
		scanf("%lf", &pary[i]->weight);
		i++;
	}

	return i - total; // 이번에 등록한 회원수를 전달
}

void total_number(int count)
{
	printf("전체 회원 수 : %d 명\n", count); // 전체 회원수를 받아와 출력
}

double average_weight(Fitness** pary, int count) // 회원 수만큼 반복해서 평균 무게 구하기
{
	if (count == 0)
	{
		printf("등록된 회원이 없습니다.\n");
		return 0;
	}

	double sum_weight = 0;
	double avg_weight = 0;

	for (int i = 0; i < count; i++)
	{
		sum_weight += pary[i]->weight;
	}
	avg_weight = sum_weight / count;

	return avg_weight;
}

int max_weight(Fitness** pary, int count) // 회원 수만큼 반복해서 최대 무게 및 index 찾기
{
	if (count == 0)
	{
		return -1;
	}

	double max_weight = 0;
	for (int i = 0; i < count; i++)
	{
		if (max_weight < pary[i]->weight) // 최대 체중 찾기
		{
			max_weight = pary[i]->weight;
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (max_weight == pary[i]->weight)
		{
			return i; // // 최대 체중에 맞는 index값 리턴
		}
	}
}

int search_info(Fitness** pary, int count, int s) // 's' 검색한 회원번호에 맞는 index 찾기
{
	for (int i = 0; i < count; i++)
	{
		if (s == pary[i]->num)
		{
			return i; // 회원 번호에 맞는 index값 리턴
		}
	}
	return -1; //검색한 회원이 없을 경우 -1 리턴
}

void print_info(Fitness** pary, int index) // index 번호에 맞는 회원 정보 출력
{
	if (index == -1) // -1은 회원이 없는 경우
	{
		printf("등록된 회원이 없습니다.\n");
	}
	else
	{
		printf("회원 번호 : ");
		printf("%d\n", pary[index]->num);
		printf("회원 이름 : ");
		printf("%s\n", pary[index]->name);
		printf("회원 체중 : ");
		printf("%.2lf\n", pary[index]->weight);
	}
}

void free_ary(Fitness** pary, int count) // 종료하면서 동적할당 해제
{
	for (int i = 0; i < count; i++)
	{
		free(pary[i]);
	}
}

void main()
{
	Fitness* ary[100];
	int choice = 0; // 메뉴 선택
	int infi = 1; // 메뉴 반복
	int count = 0, total = 0;  // 회원 수
	int index; // 회원 정보 배열 index
	int search; //검색할 회원번호
	double avgweight; // 회원 평균무게

	while (infi)
	{
		printf("=================================================================\n");
		printf("1. 회원 등록 2. 인원 수 3. 검색 4. 평균 체중 5. 최대 체중 6.종료\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("회원을 등록하세요.(번호가 음수일 경우 등록중단)\n");
			printf("=================================================================\n");
			count = input_data(ary, total); // 등록한 회원수를 불러옴
			total += count; // 기존 회원 수 + 등록한 회원 수
			break;
		case 2:
			printf("=================================================================\n");
			total_number(total);
			break;
		case 3:
			printf("=================================================================\n");
			printf("검색할 회원 번호 : ");
			scanf("%d", &search);
			index = search_info(ary, total, search);
			print_info(ary, index); // 해당 index의 회원 정보
			break;
		case 4:
			printf("=================================================================\n");
			avgweight = average_weight(ary, total);
			printf("평균 체중 : %.2lf\n", avgweight);
			break;
		case 5:
			printf("=================================================================\n");
			index = max_weight(ary, total); // 최대 체중 회원의 index
			print_info(ary, index); // 해당 index의 회원 정보
			break;
		case 6:
			free_ary(ary, total); //할당 해제
			infi = 0;
			printf("\n실행을 종료합니다.\n");
			break;
		default:
			printf("\n입력이 잘 못 되었습니다. 실행을 종료합니다.\n");
			infi = 0;
			break;
		}
	}
}