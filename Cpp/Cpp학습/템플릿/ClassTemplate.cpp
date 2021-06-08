/* 클래스 템플릿*/
#include <iostream>
using namespace std;

template<typename T> //템플릿 선언
class CTest				//일반화
{
private:
	T data;

public:
//	CTest(T anum) : num(anum) {};
	CTest(T);		//내부에서 선언
	T getData()
	{
		return data;
	}
	void printData()
	{
		cout << "num : " << data << endl;
	}
};

template <typename T> //한번 더 템플릿 선언
CTest<T>::CTest(T adata) // 외부에서 정의
{
	data = adata;
}

template <>				//특수화
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
	CTest<int> obj(10); // 일반화 템플릿 호출 (T => int)
	cout << obj.getData() << endl;

	CTest<char> obj2('A'); // 특수화 템플릿 호출
	cout << obj2.getData() << endl;
	return;
}