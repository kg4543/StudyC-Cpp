#include <stdio.h>

class Time
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
		printf("현재 시간은 %d:%d:%d 입니다.\n", hour, min, sec);
	}
};

void sub05()
{
	Time now;
	now.SetTime(12, 30, 40);
	now.OutTime();
}