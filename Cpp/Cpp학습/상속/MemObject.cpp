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
	Date valito; // �ɹ����� �̸�
	int price;

public:
	Product(const char* aname, const char* acompany, int y, int m, int d, int aprice) : valito(y, m, d) // �ʱ�ȭ ����Ʈ
	{
		strcpy(name, aname);
		strcpy(company, acompany);
		price = aprice;
	}
	void OutProduct()
	{
		printf("�̸� : %s\n", name);
		printf("������ : %s\n", company);
		printf("��ȿ�Ⱓ : ");
		valito.OutDate();
		puts("");
		printf("���� : %d\n", price);
	}
};

void sub04()
{
	Product shrimp("�����", "���", 2021, 8, 15, 900);
	shrimp.OutProduct();
}