#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

class Human2
{
private:
	char name[12];
	int age;

public:
	char* GetName() { return name; }
	void SetName(const char* aname) 
	{
		strncpy(name, aname, 12);
	}

	int GetAge() { return age; }
	void SetAge(int aage)
	{
		if (aage >= 0 && aage <= 120)
		{
			age = aage;
		}
		else
		{
			age = 0;
		}
	}

	void Setinfo(const char* aname, int aage)
	{
		strncpy(name, aname, 12);
		if (aage >= 0 && aage <= 120)
		{
			age = aage;
		}
		else
		{
			age = 0;
		}
	}

	void Info()
	{
		printf("이름: %s, 나이: %d\n", name, age);
	}
};

void sub04()
{
	Human2 man1;
	man1.SetName("Mario");
	man1.SetAge(21);
	man1.Info();

	Human2 man2;
	man2.SetName("Kimwejklfsdjklajfklasjfd");
	man2.SetAge(150);
	man2.Info();

	Human2 man3;
	man3.Setinfo("KUPA", 100);
	man3.Info();
}
