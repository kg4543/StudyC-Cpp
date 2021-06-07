#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class A
{
public:
	void AFunc()
	{
		cout << "A::AFunc()" << endl;
	}
};

class B : public A
{
public:
	void BFunc()
	{
		cout << "B::BFunc()" << endl;
	}
};

class C : public B
{
public:
	void CFunc() 
	{
		cout << "C::CFunc()" << endl;
	}
};

void sub01()
{
	A* paa = new A; // 기초 클래스 타입을 포인터가 파생객체를 가리키고 있다.
	paa->AFunc();
	A* pab = new B;
	pab->AFunc();
	A* pac = new C;
	pac->AFunc();
	
	//B* pba = new A;
	B* pba = (B*)new A; // = B* pbb = new B;
	pba->AFunc();
	pba->BFunc();

	B* pbb = new B;
	pbb->AFunc();
	pbb->BFunc();
	B* pbc = new C;
	pbc->AFunc();
	pbc->BFunc();
	
	//C* pca = new A;
	//C* pcb = new B;
	C* pcc = new C;
	pcc->AFunc();
	pcc->BFunc();
	pcc->CFunc();

	// (부모) A -> B -> C (자식)
	// 부모타입은 자식타입을 가리킬 수 있지만 자식의 함수를 사용할 수 없다.
	// 자식은 부모를 가리킬 수는 없지만 부모의 함수를 사용할 수 있다.

	return;
}