#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Human
{
private:
	char* name;

public:
	Human(const char* aname)
	{
		int len = strlen(aname) + 1;
		name = new char[len];
		strcpy_s(name, len, aname);
	}

	~Human()
	{
		delete[] name;
	}
	void printname()
	{
		cout << "My name is " << name << endl;
	}
};

class Student : public Human //
{
private:
	char* major;
	//Human person;

public:
	Student(const char* aname, const char* amajor) : Human(aname) //person(aname)
	{
		int len = strlen(amajor) + 1;
		major = new char[len];
		strcpy_s(major, len, amajor);
	}
	~Student()
	{
		delete[] major;
	}
	void printMajor()
	{
		printname();  //person.printname();
		cout << "My major is " << major << endl;
	}
};

void main()
{
	/*Human my("kim");
	my.printname();*/

	Student s1("kim", "IoT");
	s1.printMajor();
	return;
}