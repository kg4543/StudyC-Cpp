#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		hour = h;
		min = m;
		sec = s;
	}

	Time(int abssec) {
		hour = abssec / 3600;
		min = (abssec / 60) % 60;
		sec = abssec % 60;
	}

	// explicit - 명시적 변환만 허용
	explicit Time(double d) {  // 변환생성자-임시객체를 생성하여 변환하고 맴버에 대입
		hour = int(d) % 24;
		min = int((d-int(d)) * 100) % 60;
		sec = 0;
	}

	void OutTime() {
		printf("현재 시간은 %d:%d:%d입니다.\n", hour, min, sec);
	}
};

void printTime(Time when)
{
	when.OutTime();
}

void sub11()
{
	Time noon(40000);
	noon.OutTime();
	Time now = 60000;
	now.OutTime();
	now = 70000;
	now.OutTime();

	Time dnow(3.14);
	dnow.OutTime();

	printTime(80000);
}