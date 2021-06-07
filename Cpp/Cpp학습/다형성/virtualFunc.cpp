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
	A* paa = new A; // ���� Ŭ���� Ÿ���� �����Ͱ� �Ļ���ü�� ����Ű�� �ִ�.
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

	// (�θ�) A -> B -> C (�ڽ�)
	// �θ�Ÿ���� �ڽ�Ÿ���� ����ų �� ������ �ڽ��� �Լ��� ����� �� ����.
	// �ڽ��� �θ� ����ų ���� ������ �θ��� �Լ��� ����� �� �ִ�.

	return;
}