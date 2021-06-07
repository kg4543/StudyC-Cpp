#include <stdio.h>

class Time
{
private:
	int hour, min, sec;

public:
	Time() {}
	Time(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}
	void SetTime(int h, int m, int s)
	{
		hour = h;
		min = m;
		sec = s;
	}

	void OutTime() const
	{
		printf("���� �ð��� %d:%d:%d�Դϴ�.\n", hour, min, sec);
	}
	const Time AddTime(const Time& other)const
	{
		Time t;
		t.sec = sec + other.sec;
		t.min = min + other.min;
		t.hour = hour + other.hour;

		t.min += t.sec / 60;
		t.sec %= 60;
		t.hour += t.min / 60;
		t.min %= 60;
		return t;
	}
};

void sub01()
{
	Time t1(1, 10, 30);
	Time t2(2, 20, 40);
	Time t3;

	t3 = t1.AddTime(t2);
	t3.OutTime();

	const Time meeting(16, 00, 00); //��ü ���ȭ
	//meeting.SetTime(17, 00, 00);
	meeting.OutTime();
}