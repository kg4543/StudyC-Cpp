#include <stdio.h>

class Date
{
private:
	int year, month, day;

public:
	void SetDate(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}

	void outDate() {
		printf("���� ��¥�� %d:%d:%d �Դϴ�.\n", year, month, day);
	}
};

class Time : public Date 
{
private:
	int hour, min, sec;

public:
	void SetTime(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() {
		printf("���� �ð��� %d:%d:%d �Դϴ�.\n", hour, min, sec);
	}
};



void sub06()
{
	/*Date today;
	today.SetDate(2021,05,31);
	today.outDate();*/
	
	Time now;
	now.SetDate(2021, 05, 31);
	now.outDate();
	now.SetTime(12, 30, 40);
	now.OutTime();
	
}