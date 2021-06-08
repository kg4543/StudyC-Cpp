#include "cursor.h"
#include <iostream>
using namespace std;

template<typename T> // T => char
class PosValue
{
private:
	int x, y;
	T value;

public:
	PosValue() : x(0), y(0), value(0) {}
	PosValue(int ax, int ay, T av) : x(ax), y(ay), value(av) {}
	void outvalue()
	{
		gotoxy(x, y);
		cout << value << endl;
	}
};

template <typename T> // T => PosValue<char>
class Wrapper
{
private:
	T member;
public:
	void set(T v) { member = v; } // PosValue<char>(10,10,'a')를 member에 선언
	T get() { return member; }
};

void sub15()
{
	Wrapper<PosValue<char>> wrap; // template 중첩 wrap 선언
	wrap.set(PosValue<char>(10, 10, 'a')); // wrap에 void set(T v)를 호출
	PosValue<char>pc = wrap.get();
	pc.outvalue();
}