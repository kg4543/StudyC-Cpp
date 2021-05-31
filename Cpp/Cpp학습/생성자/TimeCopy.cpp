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

	void OutTime() {
		printf("현재시간은 %d:%d:%d 입니다.\n", hour, min, sec);
	}
};

void sub05()
{
	Time now(12, 34, 56);
	Time then = now;

	then.OutTime();
}