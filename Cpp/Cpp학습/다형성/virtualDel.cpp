#include <iostream>
using namespace std;

class CTest
{
private:
	int num;

public:
	CTest(int anum)
	{
		num = anum;
		cout << num << " CTest constructor" << endl;
	}
	virtual ~CTest() // ����Ҹ���
	{
		cout << num << " CTest deconstructor" << endl;
	}
	virtual void func()
	{
		cout << "CTest function()" << endl;
	}
};

class CTestSub : public CTest
{
private:
	int subN;
public:
	CTestSub(int anum, int asub) : CTest(anum)
	{
		subN = asub;
		cout << subN << " CTestSub constructor" << endl;
	}
	~CTestSub()
	{
		cout << subN << " CTestSub destructor" << endl;
	}
	void func()
	{
		cout << "CTestSub function()" << endl;
	}
};

void sub11()
{
	CTest a(10);
	a.func();
	
	CTestSub b(10, 20);
	b.func();

	CTest* pa = new CTestSub(30, 33); // �߻��ڷ������� �ڽİ�ü�� ����Ű�� �Ѵ�.
	pa->func();

	delete pa;

	return;
}