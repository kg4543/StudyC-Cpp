#include <iostream>
using namespace std;

void TestFunc1()
{
	cout << "TestFunc1() START" << endl;
	cout << "TestFunc1() END" << endl;
	//throw 0; �ι�° ȣ�⿡�� ���� �߻�
}

void TestFunc2()
{
	cout << "TestFunc2() START" << endl;
	TestFunc1();
	cout << "TestFunc2() END" << endl;
	//throw 0;
}

void TestFunc3()
{
	cout << "TestFunc3() START" << endl;
	TestFunc2();
	cout << "TestFunc3() END" << endl;
	//throw 0;
}

void sub04()
{
	try {
		TestFunc3();
	}
	catch (...) //���Ÿ��
	{
		cout << "Exception Handling" << endl;
	}
	TestFunc1();

	return;
}