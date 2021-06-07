#include <stdio.h>

class Shape
{
public:
	virtual void draw() = 0; // 순수 가상함수 : 재정의 필요
};

class Line : public Shape
{
public:
	virtual void draw()
	{
		puts("선을 긋습니다.");
	}
};

class Circle : public Shape
{
public:
	virtual void draw()
	{
		puts("동그라미 그립니다.");
	}
};

class Rect : public Shape
{
public:
	virtual void draw()
	{
		puts("사각형 그립니다.");
	}
};

void main()
{
	Shape* pS[3];

	pS[0] = new Line;
	pS[1] = new Circle;
	pS[2] = new Rect;

	for (int i = 0; i < 3; i++)
	{
		pS[i]->draw();
	}
	for (int i = 0; i < 3; i++)
	{
		delete pS[i];
	}
}