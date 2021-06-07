#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time(int h, int m, int s) {
		SetHour(h);
		SetMinute(m);
		sec = s;
	}

	int GetHour() { return hour; }
	void SetHour(int h) {
		if (h >= 0 && h < 24) {
			hour = h;
		}
	}

	int GetMinute() { return min; }
	void SetMinute(int m) {
		if (m >= 0 && m < 60)
		{
			min = m;
		}
	}
	int GetSecond() { return sec; } 

	void OutTime() {
		printf("현재시간은 %d:%d:%d 입니다.\n", hour, min, sec);
	}
};

void sub01()
{
	Time now(12, 34, 56);
	now.SetHour(40);
	now.OutTime();
	now.SetHour(9);
	now.OutTime();
}