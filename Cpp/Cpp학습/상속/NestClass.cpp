#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Product //외부 클래스
{
private:
	char name[64];
	char company[32];
	int price;

	class Date //내부클래스 : 다른 곳에서 사용 불가
	{
	protected:
		int year, month, day;

	public:
		Date(int y, int m, int d) { year = y; month = m; day = d; }
		void OutDate()
		{
			printf("%d/%d/%d", year, month, day);
		}
	};
	Date validto; // 내부클래스 객체 생성

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) : validto(y, m, d)
	{
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct()
	{
		printf("이름 : %s\n", name);
		printf("제조사 : %s\n", company);
		printf("유효기간 :");
		validto.OutDate();
		puts("");
		printf("가격 : %d\n", price);
	}
}; 

void sub06()
{
	Product shrimp("새우깡", "농심", 2020, 8, 15, 900);
	shrimp.OutProduct();
}