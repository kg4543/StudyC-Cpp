/* Ŭ���� ���ø�*/
#include <iostream>
using namespace std;

template<typename T> //���ø� ����
class CTest				//�Ϲ�ȭ
{
private:
	T data;

public:
//	CTest(T anum) : num(anum) {};
	CTest(T);		//���ο��� ����
	T getData()
	{
		return data;
	}
	void printData()
	{
		cout << "num : " << data << endl;
	}
};

template <typename T> //�ѹ� �� ���ø� ����
CTest<T>::CTest(T adata) // �ܺο��� ����
{
	data = adata;
}

template <>				//Ư��ȭ
class CTest<char>
{
private:
	char data;

public:
	CTest(char adata) : data(adata) {};
	char getData()
	{
		return data;
	}
};

void main()
{
	CTest<int> obj(10); // �Ϲ�ȭ ���ø� ȣ�� (T => int)
	cout << obj.getData() << endl;

	CTest<char> obj2('A'); // Ư��ȭ ���ø� ȣ��
	cout << obj2.getData() << endl;
	return;
}