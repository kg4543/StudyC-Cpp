#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Date
{
protected:
	int year, month, day;

public:
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
	void OutDate()
	{
		printf("%d:%d:%d", year, month, day);
	}
};

class Product
{
private:
	char name[64];
	char company[32];
	Date valito; // 맴버변수 이름
	int price;

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) : valito(y, m, d) // 초기화 리스트
	{
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct()
	{
		printf("이름 : %s\n", name);
		printf("제조사 : %s\n", company);
		printf("유효기간 : ");
		valito.OutDate();
		puts("");
		printf("가격 : %d\n", price);
	}
};

void sub04()
{
	Product shrimp("새우깡", "농심", 2021, 8, 15, 900);
	shrimp.OutProduct();
}